//
// Created by tothg on 09/05/22.
//

#include "date.h"

/// Dátum osztály operátorai és függvényei megvalósítva

int Date::getEv() const {return ev;}
int Date::getHo() const {return ho;}
int Date::getNap() const {return nap;}
/// Setterek:
//void Date::setEv(int e) {Date::ev = e;}
//void Date::setHo(int h) {Date::ho = h;}
//void Date::setNap(int n) {Date::nap = n;}

int Date::szokonapokSzama() const {
    int evek = this->ev;

    /// Ezt az évet számítani kell-e, (elmúlt-e már feb.)
    if(this->ho <= 2)
        evek--;

    return evek / 4 - evek / 100 + evek / 400;
}

/// Operátorok: ostream:
std::ostream& operator<<(std::ostream& os, const Date& rhs){
    os << std::setw(4) << rhs.getEv() << ". " << std::setw(2) << std::setfill('0')
       << rhs.getHo() << ". " << std::setw(2) << std::setfill('0') << rhs.getNap()
       << "." << std::endl;
    return os;
}
/// istream:
std::istream& operator>>(std::istream& is, Date& rhs){
    int ev, ho, nap;
    is >> ev >> ho >> nap;
    rhs = Date(ev, ho, nap);
    return is;
}
/// kivonás operátor
int Date::operator-(const Date &rhs) const {
    ///Első dátum előtt eltelt napok száma:
    long int n1 = this->getEv() * 365 + this->getNap();
    for (int i= 0; i<this->getHo()-1; i++)
        n1 += honapNapjai[i];
    n1 += this->szokonapokSzama();

    /// Második dátum előtt eltelt napok száma
    long int n2 = rhs.getEv() * 365 + rhs.getNap();
    for(int i=0; i<rhs.getHo()-1; i++)
        n2 += honapNapjai[i];
    n2 += rhs.szokonapokSzama();

    return (int)(n1 - n2);
}
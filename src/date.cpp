//
// Created by tothg on 09/05/22.
//

#include "date.h"

/// Dátum osztály operátorai és függvényei megvalósítva

int Date::getEv() const {return ev;}
int Date::getHo() const {return ho;}
int Date::getNap() const {return nap;}

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
       << ".";
    return os;
}

/// istream:
std::istream& operator>>(std::istream& is, Date& rhs){
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int year = 1900 + ltm->tm_year;
    int month = 1 + ltm->tm_mon;
    int day = ltm->tm_mday;
    int ev, ho, nap;
    while(true) {
        std::cout << "Év: ";
        is >> ev;
        while (/*is.fail() || */ev < 1900 || ev > year) {
            std::cout << "nem szám, vagy nem valid érték" << std::endl << "Év: ";
            is.clear();
            is.ignore(256, '\n');
            is >> ev;
        }
        std::cout << "Hónap: ";
        is >> ho;
        while (is.fail() || ho < 0 || ho > 12) {
            std::cout << "nem szám, vagy nem valid érték" << std::endl << "Hónap: ";
            is.clear();
            is.ignore(256, '\n');
            is >> ho;
        }
        std::cout << "Nap: ";
        is >> nap;
        while (is.fail() || nap < 0 || nap > 31) {
            std::cout << "nem szám, vagy nem valid érték" << std::endl << "Nap: ";
            is.clear();
            is.ignore(256, '\n');
            is >> nap;
        }
        if(ev == year && ho > month){
            std::cout << "Nem lehet a mai dátumnál újabb";
            continue;
        }
        if(ev == year && ho == month && nap > day) {
            std::cout << "Nem lehet a mai dátumnál újabb";
            continue;
        }
        else
            break;
    }

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
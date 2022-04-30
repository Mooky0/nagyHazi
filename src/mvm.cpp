//
// Created by tothg on 14/04/2022.
//

/// A kiírásokhoz Makró, ha def-elt kiír, ha nem, nem.
//#define DEBUG
#include "mvm.h"

#include <utility>
#include <cstring>

/// random global operatorok amik később lehet nem is kellenek, de nem tudok rendesen jó programot írni <3
/*
std::istream& operator>>(std::istream& is, std::string str){
    char c;
    while (is >> c){
        str.append(&c);
    }
    return is;
}
*/

/// Ügyfél osztály:
Ugyfel::Ugyfel() : id(0), szul(0, 0, 0), miota(0), egyenleg(0), meret(0) {
    fogyasztas = new double[miota];
    Pr("Ugyfél 0param ctor");
    //fogyasztas[miota] = 0.0;
}

Ugyfel::Ugyfel(const String& nev, int az, const Date& date, int kezdes = 0)
        : nev(String(nev)), id(az), szul(date), miota(kezdes), egyenleg(miota * 180), meret((size_t)kezdes){
    Pr("Ugyfél string ctor: " << this->nev);
    fogyasztas = new double[miota];
}

Ugyfel::Ugyfel(const char *nev, int az, const Date& date, int kezdes)
        : nev(nev), id(az), szul(date), miota(kezdes), egyenleg(miota * 180), meret((size_t)kezdes){
        /// Ebben vannak magis numberek, azokat majd mindenképpen javítani kell, mert ez most így úgy szar ahogy van.
        /// init lista végén a a egyenleg(miota * 180) az mi a fasz...?
        Pr("Ugyfél ctor: Méret: " << kezdes << " Név: " << this->nev);
        fogyasztas = new double[kezdes];
}

Ugyfel::Ugyfel( const Ugyfel& rhs){
    this->nev = rhs.nev;
    this->id = rhs.id;
    this->szul = rhs.szul;
    this->egyenleg = rhs.egyenleg;
    this->miota = rhs.miota;
    this->meret = rhs.meret;
    this->fogyasztas = new double[this->miota];
    for(int i=0; i < rhs.miota; i++){
        this->fogyasztas[i] = rhs.fogyasztas[i];
    }
    Pr("Ügyfél másoló ctor: " << this->nev);
}
Ugyfel& Ugyfel::operator=(const Ugyfel& rhs){
    if (rhs == this)
        return *this;
    this->nev = rhs.nev;
    this->id = rhs.id;
    this->szul = rhs.szul;
    this->egyenleg = rhs.egyenleg;
    this->miota = rhs.miota;
    this->meret = rhs.meret;
    delete[] fogyasztas;
    this->fogyasztas = new double[this->miota];
    for(int i=0; i < rhs.miota; i++){
        this->fogyasztas[i] = rhs.fogyasztas[i];
    }
    return *this;
}
//std::ostream& operator<<(std::ostream& os, const Ugyfel& rhs){
//    os << rhs.getNev() << "(" << rhs.getId()  << ") született: " << rhs.getSzulEv()
//        << ", nevű ügyfél adatati:\n\tEgyenleg:" << rhs.getEgyenleg() << "\n\tÜgyfél "
//        << rhs.getMiota() << "hónapja." << std::endl;
//    return os;
//}
std::ostream& operator<<(std::ostream& os, Ugyfel& rhs){
    os << rhs.getNevStr() << "(" << rhs.getId()  << ") született: " << rhs.getSzul()
        << ", nevű ügyfél adatati:\n\tEgyenleg: " << rhs.getEgyenleg() << "\n\tÜgyfél "
        << rhs.getMiota() << " hónapja." << std::endl;
    return os;
}

std::istream& operator>>(std::istream& is, Ugyfel& rhs){
    String neve;
    int id;
    Date szul;
    int mikor;
    is >> neve;
    is >> id >> szul >> mikor;

    rhs.setNev(neve);
    rhs.setId(id);
    rhs.setMiota(mikor);
    rhs.setSzulEv(szul);
    // rhs = Ugyfel(neve, id, szul, mikor);
    return is;
}

const char* Ugyfel::getNevChar() const {return nev.c_str();}
String Ugyfel::getNevStr() const {return nev;}
int Ugyfel::getId() const {return id;}
Date Ugyfel::getSzul() const {return szul;}
int Ugyfel::getMiota() const {return miota;}
int Ugyfel::getMeret() const {return meret;}
double Ugyfel::getEgyenleg() const {return egyenleg;}
double Ugyfel::getAvgFogyasztas() const {
    double sum = 0;
    for(size_t i = 0; i < meret; i++)
        sum += fogyasztas[i];
    return (sum / miota);
}

void Ugyfel::egyenlegLevon(double osszeg) {
    egyenleg -= osszeg;
}

void Ugyfel::befizet(double osszeg) {
    egyenleg += osszeg;
}

void Ugyfel::fogyasztasBejelent(double mennyi) {
    Pr("Még nem tudom ez mit csinál " << mennyi);
    auto *tmp = new double [meret];
    for (size_t i=0; i < meret; i++)
        tmp[i] = fogyasztas[i];
    delete [] fogyasztas;
    fogyasztas = new double [meret+1];
    for (size_t i =0; i < meret; i++) {
        fogyasztas[i] = tmp[i];
        Pr(i << ": " << fogyasztas[i] << "");
    }
    delete [] tmp;
    Pr("új: " << mennyi << std::endl);
    fogyasztas[meret++] = mennyi;
}

bool Ugyfel::operator==(const Ugyfel &rhs) const {
    return nev == rhs.getNevStr() &&
           id == rhs.id &&
           szul == rhs.szul &&
           miota == rhs.miota;
}

bool Ugyfel::operator==(Ugyfel *rhs) const {
    return nev == rhs->getNevStr() &&
           id == rhs->id &&
           szul == rhs->szul &&
           miota == rhs->miota;
}

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

/// Szerződés osztály
Szerzodes::Szerzodes(int e, int h, int n, const Ugyfel& kicsoda, int ar = 300, int az = 987)
    :id(az), datum(e, h, n), ugyfel(kicsoda), ar(ar) {
    Pr(this->datum);
}

Szerzodes::Szerzodes(const Date& date, const Ugyfel& kicsoda, int ar = 300, int az = 987)
    : id(az), datum(date), ugyfel(kicsoda), ar(ar) {
    Pr("Szerződés ctor: " << this->datum);
}

int Szerzodes::getId() const {return id;}
Date Szerzodes::getDate() const {return datum;}
Ugyfel& Szerzodes::getUgyfel() const {return (Ugyfel &) ugyfel;}
int Szerzodes::getAr() const {return ar;}

bool Szerzodes::operator==(const Szerzodes &rhs) const {
    return id == rhs.id &&
           datum == rhs.datum &&
           ugyfel == rhs.ugyfel &&
           ar == rhs.ar;
}

std::ostream& operator<<(std::ostream& os, Szerzodes& rhs){
    os << "Szerződés (" << rhs.getId() << ") az MVM és " <<  rhs.getUgyfel() << "\tközött: "
        << rhs.getDate() << " napon " << rhs.getAr() << "Ft/kW-ról." << std::endl;
    return os;
}

std::istream& operator>>(std::istream& is, Szerzodes& rhs){
    int az;
    Date datum;
    Ugyfel ugyfel;
    int ar;
    is >> az >> datum >> ugyfel >> ar;
    Pr(ugyfel);
    rhs.setAr(ar);
    rhs.setId(az);
    rhs.setUgyfel(ugyfel);
    rhs.setDate(datum);
    return is;
}

/// Egyéb függvények:
void szamlaz(Szerzodes& szerzodes, const Date& mettol, const Date& meddig) {
    int interval = meddig - mettol;
    double honapok = interval / 30.0;
    double fizetendo = honapok * szerzodes.getAr();
    Pr("napok =" << interval << " Honapk: " << honapok << " fizetendo: " << fizetendo);
    Pr(szerzodes);
    szerzodes.getUgyfel().Ugyfel::egyenlegLevon(fizetendo);
    Pr(szerzodes);
}

void befizet(Ugyfel &ugyfel, double osszeg) {
    ugyfel.setEgyenleg(ugyfel.getEgyenleg() + osszeg);
}





//
// Created by tothg on 14/04/2022.
//

#include "mvm.h"

/// Ügyfél osztály:
Ugyfel::Ugyfel(std::string nev, int az, int ev, int kezdes = 0)
        : nev(nev), id(az), szulEv(ev), miota(kezdes), egyenleg(miota * 180){
    fogyasztas = new double[miota];
}

Ugyfel::Ugyfel(const char *nev, int az, int ev, int kezdes = 0)
        : nev(nev), id(az), szulEv(ev), miota(kezdes), egyenleg(miota * 180){
    fogyasztas = new double[miota];
}

Ugyfel::Ugyfel(Ugyfel& rhs){
    this->nev = rhs.nev;
    this->id = rhs.id;
    this->szulEv = rhs.szulEv;
    this->egyenleg = rhs.egyenleg;
    this->miota = rhs.miota;
    this->fogyasztas = new double[this->miota];
    for(int i=0; i < rhs.miota; i++){
        this->fogyasztas[i] = rhs.fogyasztas[i];
    }
}
std::ostream& operator<<(std::ostream& os, const Ugyfel& rhs){
    os << rhs.getNev() << "(" << rhs.getId()  << ") született: " << rhs.getSzulEv()
        << ", nevű ügyfél adatati:\n\t Egyenleg:" << rhs.getEgyenleg() << "\n\tÜgyfél "
        << rhs.getMiota() << "hónapja." << std::endl;
    return os;
}

std::string Ugyfel::getNev() const {return nev;}
int Ugyfel::getId() const {return id;}
int Ugyfel::getSzulEv() const {return szulEv;}
int Ugyfel::getMiota() const {return miota;}
double Ugyfel::getEgyenleg() const {return egyenleg;}

/// Dátum osztály operátorai és függvényei megvalósítva
std::ostream& operator<<(std::ostream& os, const Date& rhs){
    os << rhs.getEv() << ". " << std::setw(2) << std::setfill('0')
        << rhs.getHo() << ". " << std::setw(2) << std::setfill('0') << rhs.getNap()
        << "." << std::endl;
    return os;
}

int Date::getEv() const {return ev;}
int Date::getHo() const {return ho;}
int Date::getNap() const {return nap;}


/// Szyődés osztály
Szerzodes::Szerzodes(int e, int h, int n) : datum(e, h, n) {
    std::cout << this->datum;
}
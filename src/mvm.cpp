//
// Created by tothg on 14/04/2022.
//

#include "mvm.h"

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
Ugyfel::Ugyfel(std::string nev, int az, int ev, int kezdes = 0)
        : nev(nev), id(az), szulEv(ev), miota(kezdes), egyenleg(miota * 180){
    fogyasztas = new double[miota];
}

Ugyfel::Ugyfel(const char *nev, int az, int ev, int kezdes = 0)
        : nev(nev), id(az), szulEv(ev), miota(kezdes), egyenleg(miota * 180){
        /// Ebben vannak magis numberek, azokat majd mindenképpen javítani kell, mert ez most így úgy szar ahogy van.
        /// init lista végén a a egyenleg(miota * 180) az mi a fasz...?
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
//std::ostream& operator<<(std::ostream& os, const Ugyfel& rhs){
//    os << rhs.getNev() << "(" << rhs.getId()  << ") született: " << rhs.getSzulEv()
//        << ", nevű ügyfél adatati:\n\tEgyenleg:" << rhs.getEgyenleg() << "\n\tÜgyfél "
//        << rhs.getMiota() << "hónapja." << std::endl;
//    return os;
//}
std::ostream& operator<<(std::ostream& os, Ugyfel& rhs){
    os << rhs.getNev() << "(" << rhs.getId()  << ") született: " << rhs.getSzulEv()
        << ", nevű ügyfél adatati:\n\tEgyenleg: " << rhs.getEgyenleg() << "\n\tÜgyfél "
        << rhs.getMiota() << " hónapja." << std::endl;
    return os;
}

std::istream& operator>>(std::istream& is, Ugyfel& rhs){
    std::string neve;
    int id;
    int szul;
    int mikor;
    std::getline(is, neve);
    is >> id >> szul >> mikor;
    rhs.setNev(neve);
    rhs.setId(id);
    rhs.setMiota(mikor);
    rhs.setSzulEv(szul);
    return is;
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


/// Szerződés osztály
Szerzodes::Szerzodes(int e, int h, int n, Ugyfel kicsoda, int ar = 300, int az = 987)
    :id(az), datum(e, h, n), ugyfel(kicsoda), ar(ar) {
    std::cout << this->datum;
}
int Szerzodes::getId() const {return id;}
Date Szerzodes::getDate() const {return datum;}
Ugyfel& Szerzodes::getUgyfel() const {return (Ugyfel &) ugyfel;}
int Szerzodes::getAr() const {return ar;}

std::ostream& operator<<(std::ostream& os, Szerzodes& rhs){
    os << "Szerződés (" << rhs.getId() << ") az MVM és " <<  rhs.getUgyfel() << "\tközött: "
        << rhs.getDate() << " napon " << rhs.getAr() << "Ft/kW-ról." << std::endl;
    return os;
}
//
// Created by tothg on 14/04/2022.
//

#ifndef NAGYHAZI_MVM_H
#define NAGYHAZI_MVM_H

#include "iostream"
#include "iomanip"
#include "string"

/// Ügyfél osztály.
///
class Ugyfel{
    std::string nev; /// az ügyfél neve.
    int id; /// Az adott ügyfél személyes azonosítója, minden ügyfélnek különböző.
    int szulEv; /// Az ügyfél születési éve
    int miota; /// Hány hónapja ügyfél, megegyezik, hogy hány hónapban fogyasztott. A fogyasztás tömb mérete.
    double egyenleg; /// Az ügygél szálmáján lévő egyenleg, lehet negatív is. [Ft]
    double* fogyasztas; /// a fogyasztás tömbje, minden hónapban mióta ügyfél mennyit fogyasztott [kWh] ?
public:
    Ugyfel(std::string nev, int az, int ev, int kezdes = 0)
        : nev(nev), id(az), szulEv(ev), miota(kezdes) {}
    Ugyfel(const char * nev, int az, int ev, int kezdes = 0)
        : nev(nev), id(az), szulEv(ev), miota(kezdes) {}
    Ugyfel(Ugyfel& rhs){
        this->nev = rhs.nev;
        this->id = rhs.id;
        this->szulEv = rhs.szulEv;
        this->egyenleg = rhs.egyenleg;
        this->fogyasztas = new double[this->miota];
        for(int i=0; i < rhs.miota; i++){
            this->fogyasztas[i] = rhs.fogyasztas[i];
        }
    }

};

/// Dátum osztály, dátumok pontos tárolásához és könnyen kezelhetőségéhez.
class Date{
    int ev, ho, nap;
public:
    /// Konstruktor év, hó, napból
    /// @param e - Év
    /// @param h - Hónap
    /// @param n - Nap
    Date(int e=0, int h=0, int n=0) : ev(e), ho(h), nap(n){
        std::cout << "Ez egy konstruktor"<< std::endl;
    }
    /// Getter függvények
    int getEv() const;
    int getHo() const;
    int getNap() const;

    /// Destruktor
    ~Date() {}
};

/// A Dátum (Date) osztályhoz tartozó operátorok:
/// outstream operator
/// @param os - ostream
/// @param rhs - kiírandó dátum
/// @return ostream
std::ostream& operator<<(std::ostream& os, const Date& rhs);


/// Szerződés osztály, szerződések tárolására
class Szerzodes{
    Date datum; ///datum amikor a szerződés köttetett.

public:
    Szerzodes(int, int, int);
};

#endif //NAGYHAZI_MVM_H

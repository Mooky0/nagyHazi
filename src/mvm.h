//
// Created by tothg on 14/04/2022.
//

#ifndef NAGYHAZI_MVM_H
#define NAGYHAZI_MVM_H

#include <iostream>
#include <iomanip>
#include <string>
#include <utility>

/// Ügyfél osztály.
///
class Ugyfel{
    std::string nev; /// az ügyfél neve.
    int id; /// Az adott ügyfél személyes azonosítója, minden ügyfélnek különböző.
    int szulEv; /// Az ügyfél születési éve
    int miota; /// Hány hónapja ügyfél, megegyezik, hogy hány hónapban fogyasztott. A fogyasztás tömb mérete.
    double egyenleg; /// Az ügygél szálmáján lévő egyenleg, lehet negatív is. [Ft]
    double* fogyasztas; /// a fogyasztás tömbje, minden hónapban mióta ügyfél mennyit fogyasztott [kW] ?
public:
    Ugyfel() {miota = 0;fogyasztas = new double[miota];};
    Ugyfel(std::string nev, int az, int ev, int kezdes); /// A kezdes def value =0, ez a cpp-ben van.
    Ugyfel(const char * nev, int az, int ev, int kezdes); /// A kezdes def value =0, ez a cpp-ben van.
    Ugyfel(Ugyfel& rhs);

    /// getter függvények:
    std::string getNev() const;
    int getId() const;
    int getSzulEv() const;
    int getMiota() const;
    double getEgyenleg() const;

    /// Setter függvények:
    void setNev(std::string n) {this->nev = n;}
    void setId(int az){this->id = az;}
    void setSzulEv(int szul){this->szulEv = szul;}
    void setMiota(int kezdes){this->miota = kezdes; delete fogyasztas; fogyasztas = new double[miota];}


    // const Ugyfel operator(const Ugyfel)(Ugyfel rhs){}

    /// dtor csak felszabít
    ~Ugyfel(){
        std::cout << "Dtor: " <<  this->nev << std::endl;
        delete[] fogyasztas;
    }
};
/// Outsream operator
/// @param os - oustream;
/// @param rhs - kiiírandó Ügyfél
std::ostream& operator<<(std::ostream& os, Ugyfel& rhs);
// std::ostream& operator<<(std::ostream& os, Ugyfel& rhs);

std::istream& operator>>(std::istream& is, Ugyfel& rhs);


/// Dátum osztály, dátumok pontos tárolásához és könnyen kezelhetőségéhez.
class Date{
    int ev, ho, nap;
public:
    /// Konstruktor év, hó, napból
    /// @param e - Év
    /// @param h - Hónap
    /// @param n - Nap
    Date(int e=0, int h=0, int n=0) : ev(e), ho(h), nap(n){
        std::cout << "Ez egy konstruktor" << std::endl;
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
    int id; ///A szerződés egyedi azonosítója, szerződészám
    Date datum; ///datum amikor a szerződés köttetett.
    Ugyfel ugyfel; /// Az ügyfél akivel a szerződés kötettet, a másik fél az MVM
    int ar; /// mennyibe kerül az áram [Ft/kW]

public:
    Szerzodes(int, int, int, Ugyfel, int, int);

    ///getter függvények:

    int getId() const;
    Date getDate() const;
    Ugyfel& getUgyfel() const;
    int getAr() const;

};

std::ostream& operator<<(std::ostream& os, Szerzodes& rhs);

#endif //NAGYHAZI_MVM_H

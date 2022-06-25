//
// Created by tothg on 09/05/22.
//

#ifndef SRC_UGYFEL_H
#define SRC_UGYFEL_H

#include "base.h"
#include "string5.h"

/// =========================== Ugyfél osztály ================================= ///
class Ugyfel : public Base{
    String nev; /// az ügyfél neve.
    int miota; /// Hány hónapja ügyfél, megegyezik, hogy hány hónapban fogyasztott.
    double egyenleg; /// Az ügygél szálmáján lévő egyenleg, lehet negatív is. [Ft]
    size_t meret; /// A fogyasztás tömb mérete, általában megegyezik a miota-val (hány hónapja ügyfél az ügfyél)
    double* fogyasztas; /// a fogyasztás tömbje, minden hónapban mióta ügyfél mennyit fogyasztott [kW] ?
public:
    Ugyfel();
    Ugyfel(const String& nev, int az, const Date& date, int kezdes, int egyenleg); /// A kezdes def value =0, ez a cpp-ben van.
    Ugyfel(const char * nev, int az, const Date& date, int kezdes = 0); /// A kezdes def value =0, ez a cpp-ben van.
    Ugyfel(const Ugyfel& rhs);

    /// getter függvények:
    const char * getNevChar() const;
    String getNevStr() const;
    int getMiota() const;
    double getEgyenleg() const;
    double getAvgFogyasztas() const;

    /// Setter függvények:
    void setNev(const String& n) {this->nev = String(n);}
    //void setSzul(const Date& szulDate){this->setDate(szulDate);}
    void setMiota(int kezdes){this->miota = kezdes;}
    void setEgyenleg(double osszeg) {this->egyenleg = osszeg;}

    ///Az egyenlegből @param osszeg levonása
    void egyenlegLevon(double osszeg);

    /// Ügyfélnek számla befizetése
    void befizet(double osszeg);

    /// Fogyasztás bejelentése
    ///
    void fogyasztasBejelent(double mennyi);

    /// Egyenlőség viusgáló operátor a egyenleget és a fogyasztást nem viszgálja
    bool operator==(const Ugyfel &rhs) const;
    bool operator==(Ugyfel* rhs) const;

    Ugyfel& operator=(const Ugyfel& rhs);

    /// dtor csak felszabít
    virtual ~Ugyfel(){
        delete [] fogyasztas;
    }
};
/// Outsream operator
/// @param os - ostream;
/// @param rhs - kiiírandó Ügyfél
std::ostream& operator<<(std::ostream& os, Ugyfel& rhs);

/// Insream operator
/// @param is - istream;
/// @param rhs - beolvasandó Ügyfél
std::istream& operator>>(std::istream& is, Ugyfel& rhs);


#endif //SRC_UGYFEL_H

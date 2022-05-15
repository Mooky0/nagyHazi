//
// Created by tothg on 09/05/22.
//

#ifndef SRC_DATE_H
#define SRC_DATE_H
#include "iostream"
#include "iomanip"
#include "fstream"
#include "ctime"

/// ======================= Dátum osztály ======================= ///

/// Hónapokban a napok számának tárolására
const int honapNapjai[12] = { 31, 28, 31, 30, 31, 30,
                              31, 31, 30, 31, 30, 31 };

/// Dátum osztály, dátumok pontos tárolásához és könnyen kezelhetőségéhez.
class Date{
    int ev, ho, nap;
public:
    /// Konstruktor év, hó, napból
    /// @param e - Év
    /// @param h - Hónap
    /// @param n - Nap
    explicit Date(int e=0, int h=0, int n=0) : ev(e), ho(h), nap(n){
    }
    Date(const Date& rhs){
        this->ev = rhs.ev;
        this->ho = rhs.ho;
        this->nap = rhs.nap;
    }

    /// Getter függvények
    int getEv() const;
    int getHo() const;
    int getNap() const;

    /// Egyenlő operator=
    /// @param rhs - másolandó dátum
    /// @return amibe máslojuk, hogy lehessen többet egymás mögé írni.
    Date& operator=(const Date& rhs)= default;

    /// Egyenlőség vizsgáló operátor
    bool operator==(const Date &rhs) const {
        return ev == rhs.ev &&
               ho == rhs.ho &&
               nap == rhs.nap;
    }

    /// Megszámolja a szökönapok számát egy @param d dátum előtt.
    int szokonapokSzama() const;

    /// Kivonás két dátumot egymásból
    /// @param
    int operator-(const Date& rhs) const;

    /// Destruktor
    ~Date() = default;
};

/// A Dátum (Date) osztályhoz tartozó operátorok:
/// outstream operator
/// @param os - ostream
/// @param rhs - kiírandó dátum
/// @return ostream
std::ostream& operator<<(std::ostream& os, const Date& rhs);


/// instream operator
/// @param is - istream
/// @param rhs - kiírandó dátum
/// @return istream
std::istream& operator>>(std::istream& is, Date& rhs);


#endif //SRC_DATE_H

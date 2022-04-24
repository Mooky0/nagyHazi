//
// Created by tothg on 14/04/2022.
//

#ifndef NAGYHAZI_MVM_H
#define NAGYHAZI_MVM_H

#include <iostream>
#include <iomanip>
#include <string>
#include <utility>
//#include <utility>

/// Debuggoláshoz kiíró makró a negyedik laborról (https://infocpp.iit.bme.hu/labor/04)
//#define DEBUG
#ifdef DEBUG
# define Pr(str) std::cout << str <<std::endl
#else
# define Pr(...)
#endif

/// Ügyfél osztály.
///
class Ugyfel{
    std::string nev; /// az ügyfél neve.
    int id; /// Az adott ügyfél személyes azonosítója, minden ügyfélnek különböző.
    int szulEv; /// Az ügyfél születési éve
    int miota; /// Hány hónapja ügyfél, megegyezik, hogy hány hónapban fogyasztott.
    double egyenleg; /// Az ügygél szálmáján lévő egyenleg, lehet negatív is. [Ft]
    size_t meret; /// A fogyasztás tömb mérete, általában megegyezik a miota-val (hány hónapja ügyfél az ügfyél)
    double* fogyasztas; /// a fogyasztás tömbje, minden hónapban mióta ügyfél mennyit fogyasztott [kW] ?
public:
    Ugyfel();
    Ugyfel(std::string nev, int az, int ev, int kezdes); /// A kezdes def value =0, ez a cpp-ben van.
    Ugyfel(const char * nev, int az, int ev, int kezdes = 0); /// A kezdes def value =0, ez a cpp-ben van.
    Ugyfel(const Ugyfel& rhs);

    /// getter függvények:
    std::string getNev() const;
    int getId() const;
    int getSzulEv() const;
    int getMiota() const;
    int getMeret() const;
    double getEgyenleg() const;
    double getAvgFogyasztas() const;

    /// Setter függvények:
    void setNev(std::string n) {this->nev = std::move(n);}
    void setId(int az){this->id = az;}
    void setSzulEv(int szul){this->szulEv = szul;}
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
    // const Ugyfel operator(const Ugyfel)(Ugyfel rhs){}

    /// dtor csak felszabít
    virtual ~Ugyfel(){
        Pr("Ugyfél dtor: " <<  this->nev);
        delete [] fogyasztas;
    }
};
/// Outsream operator
/// @param os - ostream;
/// @param rhs - kiiírandó Ügyfél
std::ostream& operator<<(std::ostream& os, Ugyfel& rhs);
// std::ostream& operator<<(std::ostream& os, Ugyfel& rhs);

/// Insream operator
/// @param is - istream;
/// @param rhs - beolvasandó Ügyfél
std::istream& operator>>(std::istream& is, Ugyfel& rhs);

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
        Pr("Dátum konstruktor: " << ev << " " << ho << " " << nap);
    }
    Date(const Date& rhs){
        this->ev = rhs.ev;
        this->ho = rhs.ho;
        this->nap = rhs.nap;
    }
    /// Setter függvények: (mivel nem használuk őket ki vannak kommentelve)
//    void setEv(int ev);
//    void setHo(int ho);
//    void setNap(int nap);

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

/// Kivonás két dátumot egymásból
/// @param
int operator-(const Date& lhs, const Date& rhs);

/// Szerződés osztály, szerződések tárolására
class Szerzodes{
    int id; ///A szerződés egyedi azonosítója, szerződészám
    Date datum; ///datum amikor a szerződés köttetett.
    Ugyfel ugyfel; /// Az ügyfél akivel a szerződés kötettet, a másik fél az MVM
    int ar; /// mennyibe kerül az áram [Ft/kW]

public:
    Szerzodes() : id(0), datum(0, 0, 0), ugyfel("Üres", 0, 0), ar(0) {};
    Szerzodes(int e, int h, int n, const Ugyfel& kicsoda, int ar, int az);
    Szerzodes(const Date&, const Ugyfel&, int, int);
    ///getter függvények:
    int getId() const;
    Date getDate() const;
    Ugyfel& getUgyfel() const;
    int getAr() const;

    /// Setter függvények: Ezeket egyelőre nem használjuk őket, mert van rá ctor
    void setId(int az){this->id = az;}
    void setDate(const Date& date){this->datum = date;}
    void setUgyfel(const Ugyfel& ugy){this->ugyfel = ugy;}
    void setAr(int ara){ this->ar = ara;}
};

std::ostream& operator<<(std::ostream& os, const Szerzodes& rhs);
std::istream& operator>>(std::istream& is, Szerzodes& rhs);

/// Egyéb függvények:


/// Számlázás:
/// Az elszámolásban egy hónap mindig 30 nap, tehát annyi hónap ahányszor 30 nap.
/// @param szerzodes - A szerződés ami alapján előállítják a számlát
/// @param meddig - a számlázott időintervallum eleje
/// @param meddig - a számlázott időintervallum vége
void szamlaz(Szerzodes& szerzodes, const Date& mettol, const Date& meddig);

/// Befizetés:
/// Ugyfél szolgáltalási díjának befizetése
/// @param ugyfel - melyik ügyfélnek
/// @param osszeg - mennyit
void befizet(Ugyfel& ugyfel, double osszeg);

#endif //NAGYHAZI_MVM_H


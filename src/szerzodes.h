//
// Created by tothg on 09/05/22.
//

#ifndef SRC_SZERZODES_H
#define SRC_SZERZODES_H

#include "base.h"
#include "ugyfel.h"
#include "debug.h"

///======================= Szerződés osztály =======================///

/// Szerződés osztály, szerződések tárolására
class Szerzodes : public Base{
    Ugyfel ugyfel; /// Az ügyfél akivel a szerződés kötettet, a másik fél az MVM
    int ar; /// mennyibe kerül az áram [Ft/kW]

public:
    Szerzodes() : Base(), ugyfel("Üres", 0, Date(0, 0, 0)), ar(0) {};
    Szerzodes(int e, int h, int n, const Ugyfel& kicsoda, int ar, int az);
    Szerzodes(const Date&, const Ugyfel&, int, int);
    ///getter függvények:
    //int getId() const override;
    //Date getDate() const override;
    Ugyfel& getUgyfel() const;
    int getAr() const;

    /// Setter függvények: Ezeket egyelőre nem használjuk őket, mert van rá ctor
    void setAz(int az){this->setId(az);}
    void setDatum(const Date& date){this->setDate(date);}
    void setUgyfel(const Ugyfel& ugy){this->ugyfel = ugy;}
    void setAr(int ara){ this->ar = ara;}

    bool operator==(const Szerzodes &rhs) const;
};

std::ostream& operator<<(std::ostream& os, const Szerzodes& rhs);
std::istream& operator>>(std::istream& is, Szerzodes& rhs);

///======================= Tároló osztály =======================///
/// Ez az osztály a 8. labor megoldásom, kisebb módosításokkal.
template<class T, int max = 10>
class Set{
    T *adat;    /// Adat tömb amit tárolunk
    int n;      /// tömb mérete
public:
    explicit Set(int n = 0) :n(n) {
        adat = new T[n];
    }
    int size(){return n;}
    bool isElement(T par) {
        Pr(Hello);
        for (int i =0; i < n; i++)
            if (adat[i] == par)
                return true;
        return false;
    }
    void insert(T par){
        if (isElement(par)){
            return;
        }
        if (n == max){
            throw "Túl sok elem";
        }
        T *temp = new T[n];
        for (int i = 0; i < n; i++){
            temp[i] = this->adat[i];
        }
        delete[] adat;
        adat = new T[n+1];
        for (int i = 0; i < n; i++){
            adat[i] = temp[i];
        }
        adat[n++] = par;
        delete [] temp;
    }
    ~Set(){delete [] adat;}
};

#endif //SRC_SZERZODES_H

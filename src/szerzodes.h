//
// Created by tothg on 09/05/22.
//

#ifndef SRC_SZERZODES_H
#define SRC_SZERZODES_H

#include "base.h"
#include "ugyfel.h"

///======================= Szerződés osztály =======================///

/// Szerződés osztály, szerződések tárolására
class Szerzodes : public Base{
    int ugyfelId; /// Az ügyfél akivel a szerződés kötettet, a másik fél az MVM
    int ar; /// mennyibe kerül az áram [Ft/kW]

public:
    Szerzodes() : Base(), ugyfelId(0), ar(0) {};
    Szerzodes(int e, int h, int n, int kicsoda, int ar, int az);
    Szerzodes(const Date&, int, int, int);
    Szerzodes(const Szerzodes& rhs);
    /// getter függvények
    int getUgyfel() const;
    int getAr() const;

    /// Setter függvények: Ezeket egyelőre nem használjuk őket, mert van rá ctor
    void setUgyfel(const int ugy){this->ugyfelId = ugy;}
    void setAr(int ara){ this->ar = ara;}

    bool operator==(const Szerzodes &rhs) const;
    Szerzodes& operator=(const Szerzodes& rhs){
        date = rhs.date;
        ugyfelId = rhs.ugyfelId;
        ar = rhs.ar;
        id = rhs.id;
        return *this;
    }
};

std::ostream& operator<<(std::ostream& os, const Szerzodes& rhs);
std::istream& operator>>(std::istream& is, Szerzodes& rhs);


#endif //SRC_SZERZODES_H

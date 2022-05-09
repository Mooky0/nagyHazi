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


#endif //SRC_SZERZODES_H

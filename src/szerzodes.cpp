//
// Created by tothg on 09/05/22.
//

#include "szerzodes.h"


/// Szerződés osztály
Szerzodes::Szerzodes(int e, int h, int n, const Ugyfel& kicsoda, int ar = 300, int az = 987)
        :Base(az, e, h, n), ugyfel(kicsoda), ar(ar) {
    //Pr(this->getDate());
}

Szerzodes::Szerzodes(const Date& date, const Ugyfel& kicsoda, int ar = 300, int az = 987)
        : Base(az, date), ugyfel(kicsoda), ar(ar) {
    //Pr("Szerződés ctor: " << this->getDate());
}

//int Szerzodes::getId() const {return id;}
//Date Szerzodes::getDate() const {return date;}
Ugyfel& Szerzodes::getUgyfel() const {return (Ugyfel &) ugyfel;}
int Szerzodes::getAr() const {return ar;}

bool Szerzodes::operator==(const Szerzodes &rhs) const {
    return id == rhs.id &&
           date == rhs.date &&
           ugyfel == rhs.ugyfel &&
           ar == rhs.ar;
}

std::ostream& operator<<(std::ostream& os, const Szerzodes& rhs){
    os << "Szerződés (" << rhs.getId() << ") az MVM és " <<  rhs.getUgyfel() << "\tközött: "
       << rhs.getDate() << " napon " << rhs.getAr() << "Ft/kW-ról." << std::endl;
    return os;
}

std::istream& operator>>(std::istream& is, Szerzodes& rhs){
    int az;
    Date datum;
    Ugyfel ugyfel;
    int ar;
    is >> az >> datum >> ugyfel >> ar;
    //Pr(ugyfel);
    rhs.setAr(ar);
    rhs.setId(az);
    rhs.setUgyfel(ugyfel);
    rhs.setDate(datum);
    return is;
}
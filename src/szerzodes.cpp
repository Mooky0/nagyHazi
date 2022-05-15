//
// Created by tothg on 09/05/22.
//

#include "szerzodes.h"


/// Szerződés osztály
Szerzodes::Szerzodes(int e, int h, int n, int kicsoda, int ar = 300, int az = 987)
        :Base(az, e, h, n), ugyfelId(kicsoda), ar(ar) {
    //Pr(this->getDate());
}

Szerzodes::Szerzodes(const Date& date, int kicsoda, int ar = 300, int az = 987)
        : Base(az, date), ugyfelId(kicsoda), ar(ar) {
    //Pr("Szerződés ctor: " << this->getDate());
}

Szerzodes::Szerzodes(const Szerzodes &rhs): Base(rhs.id, rhs.date), ugyfelId(rhs.ugyfelId), ar(rhs.ar) {
}

int Szerzodes::getUgyfel() const {return ugyfelId;}
int Szerzodes::getAr() const {return ar;}

bool Szerzodes::operator==(const Szerzodes &rhs) const {
    return id == rhs.id &&
           date == rhs.date &&
           ugyfelId == rhs.ugyfelId &&
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
    int ugyfelaz;
    int ar;
    std::cout << "Megkötés dátuma: ";
    is >> datum;
    std::cout << "Ügyfél azonosítója: ";
    is >> ugyfelaz;
    std::cout << "Havidíj: ";
    is >> ar;
    std::cout << "Azonosító: ";
    std::cin >> az;
    rhs.setAr(ar);
    rhs.setId(az);

    rhs.setUgyfel(ugyfelaz);
    rhs.setDate(datum);
    return is;
}
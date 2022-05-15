//
// Created by tothg on 09/05/22.
//

#include "szerzodes.h"


/// Szerződés osztály
Szerzodes::Szerzodes(int e, int h, int n, int kicsoda, int ar = 300, int az = 987)
        :Base(az, e, h, n), ugyfelId(kicsoda), ar(ar) {
}

Szerzodes::Szerzodes(const Date& date, int kicsoda, int ar = 300, int az = 987)
        : Base(az, date), ugyfelId(kicsoda), ar(ar) {
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
    while(is.fail()){
        std::cout << "Nem megfelelő azonosító" << std::endl;
        is.clear();
        is.ignore(256, '\n');
        std::cout << "Ügyfél azonosító: ";
        std::cin >> ugyfelaz;
    }
    std::cout << "Havidíj: ";
    is >> ar;
    while(is.fail()){
        std::cout << "Nem megfelelő azonosító" << std::endl;
        is.clear();
        is.ignore(256, '\n');
        std::cout << "Havidíj: ";
        is >> ar;
    }
    std::cout << "Szerződés azonosító: ";
    std::cin >> az;
    while(is.fail()){
        std::cout << "Nem megfelelő azonosító" << std::endl;
        is.clear();
        is.ignore(256, '\n');
        std::cout << "Szerződés azonosító: ";
        is >> az;
    }
    rhs.setAr(ar);
    rhs.setId(az);

    rhs.setUgyfel(ugyfelaz);
    rhs.setDate(datum);
    return is;
}
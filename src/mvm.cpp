//
// Created by tothg on 14/04/2022.
//

#include "mvm.h"

std::ostream& operator<<(std::ostream& os, const Date& rhs){
    os << rhs.getEv() << ". " << std::setw(2) << std::setfill('0')
        << rhs.getHo() << ". " << std::setw(2) << std::setfill('0') << rhs.getNap()
        << "." << std::endl;
    return os;
}

int Date::getEv() const {
    return ev;
}
int Date::getHo() const {
    return ho;
}
int Date::getNap() const {
    return nap;
}

Szerzodes::Szerzodes(int e, int h, int n) : datum(e, h, n) {
    std::cout << this->datum;
}
//
// Created by tothg on 14/04/2022.
//

/// A kiírásokhoz Makró, ha def-elt kiír, ha nem, nem.
//#define DEBUG
#include "mvm.h"

#include <utility>
#include <cstring>








/// Egyéb függvények:
void szamlaz(Szerzodes& szerzodes, const Date& mettol, const Date& meddig) {
    int interval = meddig - mettol;
    double honapok = interval / 30.0;
    double fizetendo = honapok * szerzodes.getAr();
    Pr("napok =" << interval << " Honapk: " << honapok << " fizetendo: " << fizetendo);
    Pr(szerzodes);
    szerzodes.getUgyfel().Ugyfel::egyenlegLevon(fizetendo);
    Pr(szerzodes);
}

void befizet(Ugyfel &ugyfel, double osszeg) {
    ugyfel.setEgyenleg(ugyfel.getEgyenleg() + osszeg);
}

double egyenlegLekerdez(const Ugyfel &ugyfel) {
    return ugyfel.getEgyenleg();
}





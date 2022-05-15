//
// Created by tothg on 14/04/2022.
//

#ifndef NAGYHAZI_MVM_H
#define NAGYHAZI_MVM_H


#include "string5.h"


#include "date.h"
#include "base.h"
#include "ugyfel.h"
#include "set.hpp"
#include "szerzodes.h"

/// =========================== Egyéb függvények ========================

/// Számlázás:
/// Az elszámolásban egy hónap mindig 30 nap, tehát annyi hónap ahányszor 30 nap.
/// @param szerzodes - A szerződés ami alapján előállítják a számlát
/// @param meddig - a számlázott időintervallum eleje
/// @param meddig - a számlázott időintervallum vége
void szamlaz(Szerzodes& szerzodes, const Date& mettol, const Date& meddig, Set<Ugyfel>& ugyfelek);

/// Befizetés:
/// Ugyfél szolgáltalási díjának befizetése
/// @param ugyfel - melyik ügyfélnek
/// @param osszeg - mennyit
void befizet(Ugyfel& ugyfel, double osszeg);

/// Egyenleg lekérdezése:
/// csak hogy legyen egy globalis fv is, mert miért ne.
/// @param ugyfel - melyik ügyfélnek?
/// @return - mennyi az üél egyenlege
double egyenlegLekerdez(const Ugyfel& ugyfel);

void fileKiir(const Set<Ugyfel>&, const Set<Szerzodes>&);

Set<Ugyfel> ugyfelekBeolvas();

Set<Szerzodes> szerzodesekBeolvas();

#endif //NAGYHAZI_MVM_H


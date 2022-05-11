//
// Created by tothg on 14/04/2022.
//

/// A kiírásokhoz Makró, ha def-elt kiír, ha nem, nem.
//#define DEBUG
#include "mvm.h"
#include "fstream"
#include "iostream"

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

void fileKiir(const Set<Ugyfel>& s0, const Set<Szerzodes>& s1) {
    std::ofstream ugyfelekFile("ugyfelek.txt");
    //ugyfelekFile << "Hello world!" << std::endl;
    for ( int i = 0; i < s0.size(); i++){
        ugyfelekFile << s0[i].getId() << s0[i].getNevStr() << " " << s0[i].getEgyenleg() << " " << s0[i].getMiota() << " "
            << s0[i].getDate().getEv() << " " << s0[i].getDate().getHo() << " " << s0[i].getDate().getNap() << std::endl;
    }
    ugyfelekFile.close();
    std::ofstream szerzFile("szerzodesek.txt");
    for (int i = 0; i < s1.size(); i++){
        szerzFile << s1[i].getId() << " " << s1[i].getUgyfel().getNevStr() << " " << s1[i].getUgyfel().getEgyenleg() << " " << s1[i].getUgyfel().getMiota() << " "
        << s1[i].getUgyfel().getDate().getEv() << " " << s1[i].getUgyfel().getDate().getHo() << " " << s1[i].getUgyfel().getDate().getNap() << " "
        << s1[i].getAr() << " " << s1[i].getDate().getEv() << " "  << s1[i].getDate().getHo() << " " << s1[i].getDate().getNap() << std::endl;
    }
    szerzFile.close();
}

Set<Ugyfel> ugyfelekBeolvas() {
    std::ifstream ugyfelekFile("ugyfelek.txt");
    //Ugyfel u;
    Set<Ugyfel> s; /// Ezt adjuk majd vissza, a Set;
    String nev;
    int id, egyenleg, miota, ev, ho, nap;
    Pr("Igen");
    while(ugyfelekFile >> id >> nev  >> egyenleg >> miota >> ev >> ho >> nap) {
        //std::cout << std::endl << "Vége" << std::endl;
        Pr("insert előtt");
        s.insert(Ugyfel(nev, id, Date(ev, ho, nap), miota));
        Pr("Instert után");
    }
    if(!ugyfelekFile.eof())
        throw "Hibás a fáj formátuma";
    ugyfelekFile.close();
    return s;
}

Set<Szerzodes> szerzodesekBeolvas() {
    std::ifstream szerzFile("szerzodesek.txt");
    Set<Szerzodes> s;
    String nev;
    int az, egyenleg, miota, uev, uho, unap, ar, szev, szho, sznap;
    while(szerzFile >> az >> nev >> egyenleg >> miota >> uev >> uho >> unap >> ar >> szev >> szho >> sznap){
        Ugyfel u(nev, az, Date(uev, uho, unap), miota);
        s.insert(Szerzodes(szev, szho, sznap, u, ar, az));
    }
    if(!szerzFile.eof())
        throw "Hibás a fáj formátuma";
    szerzFile.close();
    return s;
}





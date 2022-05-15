//
// Created by tothg on 14/04/2022.
//

#include "mvm.h"
#include "iostream"

/// Egyéb függvények:
void szamlaz(Szerzodes& szerzodes, const Date& mettol, const Date& meddig, Set<Ugyfel>& ugyfelek) {
    int interval = meddig - mettol;
    double honapok = interval / 30.0;
    double fizetendo = honapok * szerzodes.getAr();
    int az = ugyfelek.lookup(szerzodes.getUgyfel());
    if (az == -1){
        throw std::out_of_range("Nincs ilyen");
    }
    ugyfelek[az].Ugyfel::egyenlegLevon(fizetendo);
}

void befizet(Ugyfel &ugyfel, double osszeg) {
    ugyfel.setEgyenleg(ugyfel.getEgyenleg() + osszeg);
}

double egyenlegLekerdez(const Ugyfel &ugyfel) {
    return ugyfel.getEgyenleg();
}

void fileKiir(const Set<Ugyfel>& s0, const Set<Szerzodes>& s1) {
    std::ofstream ugyfelekFile("ugyfelek.txt");
    for ( int i = 0; i < s0.size(); i++){
        ugyfelekFile << s0[i].getId() << " " << s0[i].getNevStr() << s0[i].getEgyenleg() << " " << s0[i].getMiota() << " "
            << s0[i].getDate().getEv() << " " << s0[i].getDate().getHo() << " " << s0[i].getDate().getNap();
        if(i != s0.size()-1)
            ugyfelekFile << std::endl;
    }
    ugyfelekFile.close();
    std::ofstream szerzFile("szerzodesek.txt");
    for (int i = 0; i < s1.size(); i++){
        szerzFile << s1[i].getId() << " " << s1[i].getUgyfel() << " "
        << s1[i].getAr() << " " << s1[i].getDate().getEv() << " "  << s1[i].getDate().getHo() << " " << s1[i].getDate().getNap();
        if (i != s1.size()-1)
            szerzFile << std::endl;
    }
    szerzFile.close();
}

Set<Ugyfel> ugyfelekBeolvas() {
    std::ifstream ugyfelekFile("ugyfelek.txt");
    Set<Ugyfel> s; /// Ezt adjuk majd vissza, a Set;
    String nev;
    int id, egyenleg, miota, ev, ho, nap;
    while(!ugyfelekFile.eof()) {
        ugyfelekFile >> id;
        char c;
        nev = String("");
        std::ios_base::fmtflags fl = ugyfelekFile.flags();
        ugyfelekFile.setf(std::ios_base::skipws);
        while(ugyfelekFile >> c){
            ugyfelekFile.unsetf(std::ios_base::skipws);
            if (c == '\n' || c == '\0' || isdigit(c)) {
                ugyfelekFile.putback(c);
                break;
            } else {
                nev = nev + c;
            }

        }
        ugyfelekFile.setf(fl);
        ugyfelekFile >> egyenleg >> miota >> ev >> ho >> nap;
        s.insert(Ugyfel(nev, id, Date(ev, ho, nap), miota, egyenleg));
    }
    if(!ugyfelekFile.eof()){
        ugyfelekFile.close();
        throw "Hibás a fáj formátuma";

    }
    ugyfelekFile.close();
    return s;
}

Set<Szerzodes> szerzodesekBeolvas() {
    std::ifstream szerzFile("szerzodesek.txt");
    Set<Szerzodes> s;
    String nev;
    int az, ar, szev, szho, sznap;
    int uaz;
    while(szerzFile >> az >> uaz >> ar >> szev >> szho >> sznap){
        s.insert(Szerzodes(szev, szho, sznap, uaz, ar, az));
    }
    if(!szerzFile.eof())
        throw "Hibás a fáj formátuma";
    szerzFile.close();
    return s;
}





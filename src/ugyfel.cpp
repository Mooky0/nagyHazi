//
// Created by tothg on 09/05/22.
//

#include "ugyfel.h"
#include "string5.h"

/// =========================== Ugyfél osztály ================================= ///
Ugyfel::Ugyfel() : Base(), miota(0), egyenleg(0), meret(0) {
    fogyasztas = new double[miota];
    //Pr("Ugyfél 0param ctor");
    //fogyasztas[miota] = 0.0;
}

Ugyfel::Ugyfel(const String& nev, int az, const Date& date, int kezdes = 0)
        : Base(az, date), nev(String(nev)), miota(kezdes), egyenleg(miota * 180), meret((size_t)kezdes){
    //Pr("Ugyfél string ctor: " << this->nev);
    fogyasztas = new double[miota];
}

Ugyfel::Ugyfel(const char *nev, int az, const Date& date, int kezdes)
        : Base(az, date), nev(nev), miota(kezdes), egyenleg(miota * 180), meret((size_t)kezdes){
    /// Ebben vannak magis numberek, azokat majd mindenképpen javítani kell, mert ez most így úgy szar ahogy van.
    /// init lista végén a a egyenleg(miota * 180) az mi a fasz...?
    //Pr("Ugyfél ctor: Méret: " << kezdes << " Név: " << this->nev);
    fogyasztas = new double[kezdes];
}

Ugyfel::Ugyfel( const Ugyfel& rhs) : Base(rhs) {
    this->nev = rhs.nev;
    this->id = rhs.id;
    this->date = rhs.date;
    this->egyenleg = rhs.egyenleg;
    this->miota = rhs.miota;
    this->meret = rhs.meret;
    this->fogyasztas = new double[this->miota];
    for(int i=0; i < rhs.miota; i++){
        this->fogyasztas[i] = rhs.fogyasztas[i];
    }
    //Pr("Ügyfél másoló ctor: " << this->nev);
}
Ugyfel& Ugyfel::operator=(const Ugyfel& rhs){
    if (rhs == this)
        return *this;
    this->nev = rhs.nev;
    this->id = rhs.id;
    this->date = rhs.date;
    this->egyenleg = rhs.egyenleg;
    this->miota = rhs.miota;
    this->meret = rhs.meret;
    delete[] fogyasztas;
    this->fogyasztas = new double[this->miota];
    for(int i=0; i < rhs.miota; i++){
        this->fogyasztas[i] = rhs.fogyasztas[i];
    }
    return *this;
}
//std::ostream& operator<<(std::ostream& os, const Ugyfel& rhs){
//    os << rhs.getNev() << "(" << rhs.getId()  << ") született: " << rhs.getSzulEv()
//        << ", nevű ügyfél adatati:\n\tEgyenleg:" << rhs.getEgyenleg() << "\n\tÜgyfél "
//        << rhs.getMiota() << "hónapja." << std::endl;
//    return os;
//}
std::ostream& operator<<(std::ostream& os, Ugyfel& rhs){
    os << rhs.getNevStr() << "(" << rhs.getId()  << ") született: " << rhs.getDate()
       << ", nevű ügyfél adatati:\n\tEgyenleg: " << rhs.getEgyenleg() << "\n\tÜgyfél "
       << rhs.getMiota() << " hónapja." << std::endl;
    return os;
}
std::ofstream& operator<<(std::ofstream& os, const Ugyfel& rhs){
    os << rhs.getNevStr() << std::endl << rhs.getId() << std::endl << rhs.getEgyenleg() << rhs.getEgyenleg() << std::endl << std::endl;
    return os;
}


std::istream& operator>>(std::istream& is, Ugyfel& rhs){
    String neve;
    int id;
    Date szul;
    int mikor;
    is >> neve;
    is >> id >> szul >> mikor;

    rhs.setNev(neve);
    rhs.setId(id);
    rhs.setMiota(mikor);
    rhs.setDate(szul);
    // rhs = Ugyfel(neve, id, szul, mikor);
    return is;
}

const char* Ugyfel::getNevChar() const {return nev.c_str();}
String Ugyfel::getNevStr() const {return nev;}
//int Ugyfel::getId() const {return id;}
//Date Ugyfel::getSzul() const {return this->getDate();}
int Ugyfel::getMiota() const {return miota;}
int Ugyfel::getMeret() const {return meret;}
double Ugyfel::getEgyenleg() const {return egyenleg;}
double Ugyfel::getAvgFogyasztas() const {
    double sum = 0;
    for(size_t i = 0; i < meret; i++)
        sum += fogyasztas[i];
    return (sum / miota);
}

void Ugyfel::egyenlegLevon(double osszeg) {
    egyenleg -= osszeg;
}

void Ugyfel::befizet(double osszeg) {
    egyenleg += osszeg;
}

void Ugyfel::fogyasztasBejelent(double mennyi) {
    //Pr("Még nem tudom ez mit csinál " << mennyi);
    auto *tmp = new double [meret];
    for (size_t i=0; i < meret; i++)
        tmp[i] = fogyasztas[i];
    delete [] fogyasztas;
    fogyasztas = new double [meret+1];
    for (size_t i =0; i < meret; i++) {
        fogyasztas[i] = tmp[i];
        //Pr(i << ": " << fogyasztas[i] << "");
    }
    delete [] tmp;
    //Pr("új: " << mennyi << std::endl);
    fogyasztas[meret++] = mennyi;
}

bool Ugyfel::operator==(const Ugyfel &rhs) const {
    return nev == rhs.getNevStr() &&
           id == rhs.id &&
           date == rhs.date &&
           miota == rhs.miota;
}

bool Ugyfel::operator==(Ugyfel *rhs) const {
    return nev == rhs->getNevStr() &&
           id == rhs->id &&
           date == rhs->date &&
           miota == rhs->miota;
}
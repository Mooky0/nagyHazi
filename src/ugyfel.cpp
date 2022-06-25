//
// Created by tothg on 09/05/22.
//

#include "ugyfel.h"
#include "string5.h"

/// =========================== Ugyfél osztály ================================= ///
Ugyfel::Ugyfel() : Base(), miota(0), egyenleg(0), meret(0) {
    fogyasztas = new double[miota];
}

Ugyfel::Ugyfel(const String& nev, int az, const Date& date, int kezdes = 0, int egyenleg = 0)
        : Base(az, date), nev(String(nev)), miota(kezdes), egyenleg(egyenleg), meret((size_t)kezdes){
    fogyasztas = new double[miota];
}

Ugyfel::Ugyfel(const char *nev, int az, const Date& date, int kezdes)
        : Base(az, date), nev(nev), miota(kezdes), egyenleg(miota * 180), meret((size_t)kezdes){
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
std::ostream& operator<<(std::ostream& os, Ugyfel& rhs){
    os << rhs.getNevStr() << "(" << rhs.getId()  << ") született: " << rhs.getDate()
       << ", nevű ügyfél adatati:\n\tEgyenleg: " << rhs.getEgyenleg() << "\n\tÜgyfél "
       << rhs.getMiota() << " hónapja." << std::endl;
    return os;
}

std::istream& operator>>(std::istream& is, Ugyfel& rhs){
    String neve;
    int id;
    Date szul;
    std::cout << "Adja meg a nevt: ";
    is >> neve;
    std::cout << "Azonosító: ";
    is >> id;
    while(is.fail()){
        std::cout << "nem megfelelő formátum" << std::endl << "Azonosító: ";
        is.clear();
        is.ignore(256, '\n');
        is >> id;
    }
    std::cout << "Születési dátum: ";
    is >> szul;

    rhs.setNev(neve);
    rhs.setId(id);
    rhs.setMiota(0);
    rhs.setDate(szul);
    // rhs = Ugyfel(neve, id, szul, mikor);
    return is;
}

const char* Ugyfel::getNevChar() const {return nev.c_str();}
String Ugyfel::getNevStr() const {return nev;}
int Ugyfel::getMiota() const {return miota;}
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
    auto *tmp = new double [meret];
    for (size_t i=0; i < meret; i++)
        tmp[i] = fogyasztas[i];
    delete [] fogyasztas;
    fogyasztas = new double [meret+1];
    for (size_t i =0; i < meret; i++) {
        fogyasztas[i] = tmp[i];
    }
    delete [] tmp;
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
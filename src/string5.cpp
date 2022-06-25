/**
 *
 * \file string5.cpp
 *
 * Itt kell megvalósítania a hiányzó tagfüggvényeket.
 * Segítségül megadtuk a C++ nem OO eszközeinek felhasználásával készített String-kezelő
 * függvényke neveit.
 *
 * Ha valamit INLINE-ként valósít meg, akkor annak a string5.h-ba kell kerülnie,
 * akár kívül akár osztályon belül definiálja. (Az inline függvényeknek minden
 * fordítási egységben elérhetőknek kell lenniük)
 * *
 * A teszteléskor ne felejtse el beállítani a string5.h állományban az ELKESZULT makrót.
 *
 */

#ifdef _MSC_VER
// MSC ne adjon figyelmeztető üzenetet a C sztringkezelő függvényeire
  #define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>             // Kiíratáshoz
#include <cstring>              // Sztringműveletekhez

#include "memtrace.h"           // a standard headerek után kell lennie
#include "string5.h"


/// Konstruktorok: egy char karakterből (createString)
///                egy nullával lezárt char sorozatból (createString)
String::String(char const c) {
    len = 1;
    pData = new char [len + 1];
    pData[0] = c;
    pData[1] = '\0';
}

String::String(char const* str) {
    len = strlen(str);
    pData = new char [len + 1];
    strcpy(pData, str);
}


/// Másoló konstruktor: String-ből készít (createString)
String::String(String const & str) {
    len = strlen(str.c_str());
    pData = new char [len + 1];
    strcpy(pData, str.c_str());
}

/// Destruktor (disposeString)
String::~String() {
    delete[] pData;
}

/// operator=
String &String::operator=(const String& str) {
    delete[] pData;
    len = strlen(str.c_str());
    pData = new char [len + 1];
    strcpy(pData, str.c_str());
    return *this;
}

/// [] operátorok: egy megadott indexű elem REFERENCIÁJÁVAL térnek vissza (charAtString)
/// indexhiba esetén const char * kivételt dob!
const char& String::operator[](size_t idx) const {
    if (idx > this->len-1 || idx < 0) throw "F041OM";
    return this->pData[idx];
}
char& String::operator[](size_t idx) {
    if (idx > this->len-1 || idx < 0) throw "F041OM";
    return this->pData[idx];
}


/// + operátorok:
///                 String-hez jobbról karaktert ad (addString)
///                 String-hez String-et ad (addString)
String String::operator+(const String& str) const {
    String res;
    res.len = this->len + str.len;
    res.pData = new char[res.len +1];
    strcpy(res.pData, this->c_str());
    strcat(res.pData, str.c_str());
    return res;
}
String String::operator+(const char c) const {
    String res;
    res.len = this->len+1;
    res.pData = new char[res.len + 1];
    strcpy(res.pData, this->pData);
    res.pData[res.len-1] = c;
    res.pData[res.len] = '\0';
    return res;
}

String operator+(char c, const String& str){
    String s1(c);
    return s1 + str;
}

/// << operator, ami kiír az ostream-re
std::ostream& operator<<(std::ostream& os, const String& rhs){
    os << rhs.c_str();
    return os;
}

/// >> operátor, ami beolvas az istream-ről egy szót
std::istream& operator>>(std::istream& is, String& rhs){
    char c;
    rhs = String("");
    std::ios_base::fmtflags fl = is.flags();
    is.setf(std::ios_base::skipws);
    while(is >> c){
        is.unsetf(std::ios_base::skipws);
        if (c == '\n' || c == '\0') {
            is.putback(c);
            break;
        } else {
            rhs = rhs + c;
        }

    }
    is.setf(fl);
    return is;
}

/// Egyéb módosítások
bool String::operator==(const String &rhs) const {
    return (strcmp(this->c_str(), rhs.c_str()) == 0);
}

bool String::operator==(const char *rhs) const {
    return  (strcmp(this->c_str(), rhs) == 0);
}

String& String::operator=(const char * rhs){
    len = strlen(rhs);
    delete [] pData;
    pData = new char[len];
    strcpy(pData, rhs);
    return *this;
}
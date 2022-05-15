//
// Created by tothg on 09/05/22.
//

#ifndef SRC_BASE_H
#define SRC_BASE_H

#include "date.h"

/// =========================== Base osztály =================================== ///
/// alaposztály amiből az Ügyfél és a Szerzdés örököl, dátumot és azonosítót.
class Base{
protected:
    int id; /// Az ugyfél vagy a szerződés azonosítója
    Date date; /// dátum, az Ugyfélnél születási év, a Szerződésnél, a megkötés dátuma.
public:
    Base();
    Base(int, const Date&);
    Base(int, int, int, int);

    int getId() const;
    Date getDate() const;
    void setDate(const Date&);
    void setId(int);
};

#endif //SRC_BASE_H

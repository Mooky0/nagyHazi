//
// Created by tothg on 09/05/22.
//

#include "base.h"

/// =========================== Base osztály =================================== ///
Base::Base() : id(0), date(0) {}
Base::Base(int az, const Date& datum) :id(az), date(datum) {}
Base::Base(int az, int e , int h , int n) :id(az), date(e, h, n) {}

int Base::getId() const {return  id;}
Date Base::getDate() const {return date;}

void Base::setDate(const Date &datum) {date = datum;}
void Base::setId(const int az) {id = az;}

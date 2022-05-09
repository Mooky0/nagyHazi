//
// Created by tothg on 09/05/22.
//

#ifndef SRC_DEBUG_H
#define SRC_DEBUG_H

/// Debuggoláshoz kiíró makró a negyedik laborról (https://infocpp.iit.bme.hu/labor/04)
//#define DEBUG
#ifdef DEBUG
# define Pr(str) std::cout << str <<std::endl
#else
# define Pr(...)
#endif

#endif //SRC_DEBUG_H

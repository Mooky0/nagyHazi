#include <iostream>

//#define DEBUG
#include "mvm.h"
//#define MEMTRACE
#include "gtest_lite.h"
#include "memtrace.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    TEST(Datumteszt, Konstruktor)
        Date d0(2022, 4, 14);
        ASSERT_NO_THROW(std::cout << d0;)
        Date d1;
        std::cout << d1;
    END


    TEST(Ugyfel, Konstruktor)
        Ugyfel u0("Jancsi Jóska", 123, 2022, 3);
        Ugyfel u1(u0);
        std::string str = "Hello bello";
        Ugyfel u2(str, 124, 1990, 4);
        std::cout << u0;
        std::cout << u1;
        std::cout << u2;
    END
    TEST(Ugyfel, Input)
        Ugyfel u2/*("Helloka Belloka", 120, 2000, 15)*/;
        std::istringstream iss("Helloka Belloka\n120 2000 15");
        iss >> u2;
        EXPECT_EQ("Helloka Belloka", u2.getNev());
        EXPECT_EQ(120, u2.getId());
        EXPECT_EQ(2000, u2.getSzulEv());
        EXPECT_EQ(15, u2.getMiota());
    END

    TEST(Szerzodes, Konstruktor)
        Ugyfel u0("Enci Penci2", 124, 2013, 6);
        Szerzodes sz0(2003, 1, 29, u0, 300, 987);
        std::cout << sz0;
    END
    TEST(Szerzodes, Input)
        Szerzodes sz0;
        std::istringstream iss("45 1970 01 01Random Ugyfél\n666 1600 3 600");
        Pr("tudod hol kell keresni ;)");
        iss >> sz0;
        Pr("Itt is jó");
        EXPECT_EQ(45, sz0.getId());
        Pr("Eddig jó");
        EXPECT_EQ(Date(1970, 01, 01), sz0.getDate());
        Pr("Még megvan!");
        Ugyfel u0("Random Ugyfél", 666, 1600, 3);
        Pr("Az ugyfél ctor jó:" << u0);
        //std::cout << "sz0 Ugyfele:" << sz0.getUgyfel();
        EXPECT_EQ(u0, sz0.getUgyfel());
        //std::cout << "Még megvan!2" << std::endl;
        EXPECT_EQ(600, sz0.getAr());
    END

    /*
    TEST(Random, valami)
        std::cout << "Szia!" << std::endl;
    END
    */
    return 0;
}
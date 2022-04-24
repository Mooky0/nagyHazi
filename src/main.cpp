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
        EXPECT_EQ(2022, d0.getEv());
        EXPECT_EQ(4, d0.getHo());
        EXPECT_EQ(14, d0.getNap());
        Date d1;
        EXPECT_EQ(0, d1.getEv());
        EXPECT_EQ(0, d1.getHo());
        EXPECT_EQ(0, d1.getNap());
    END
    TEST(Datumteszt, Kivonas)
        Date d0(2000, 2, 1);
        Date d1(2004, 2, 1);
        int kul0 = d1 - d0;
        EXPECT_EQ(1461, kul0);

        Date d2(2020, 11, 12);
        Date d3(2022, 4, 23);
        int kul1 = d3 - d2;
        EXPECT_EQ(527, kul1);

        Date d4(2020, 10, 2);
        Date d5(2022, 4,25);
        int kul2 = d5 - d4;
        EXPECT_EQ(570, kul2);
    END


    TEST(Ugyfel, Konstruktor)
        Ugyfel u0("Jancsi Jóska", 123, 2022, 3);
        Ugyfel u1(u0);
        std::string str = "Hello bello";
        Ugyfel u2(str, 124, 1990, 4);
        EXPECT_EQ("Jancsi Jóska", u0.getNev());
        EXPECT_EQ(123, u0.getId());
        EXPECT_EQ(2022, u0.getSzulEv());
        EXPECT_EQ(3, u0.getMiota());
        EXPECT_EQ(Ugyfel("Jancsi Jóska", 123, 2022, 3), u1);
        EXPECT_EQ(Ugyfel("Hello bello", 124, 1990, 4), u2);
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

    TEST(Ugyfel, befizet)
        /// Befizetés globális fv-vel
        Ugyfel u2("Helloka Belloka", 120, 2000, 15);
        u2.setEgyenleg(1500);
        befizet(u2, 300);
        EXPECT_EQ(1800, u2.getEgyenleg());

        /// Befizetés tagfv-vel
        u2.befizet(200);
        EXPECT_EQ(2000, u2.getEgyenleg());
    END

    TEST(Szerzodes, Konstruktor)
        Ugyfel u0("Enci Penci2", 124, 2013, 6);
        Szerzodes sz0(2003, 1, 29, u0, 300, 987);
        EXPECT_EQ(Date(2003, 1, 29), sz0.getDate());
        EXPECT_EQ(Ugyfel("Enci Penci2", 124, 2013, 6), sz0.getUgyfel());
        EXPECT_EQ(300, sz0.getAr());
        EXPECT_EQ(987, sz0.getId());

        Date d0(2000, 8, 6);
        Szerzodes sz1(d0, u0, 500, 654);
        EXPECT_EQ(Date(2000, 8, 6), sz1.getDate());
        EXPECT_EQ(Ugyfel("Enci Penci2", 124, 2013, 6), sz1.getUgyfel());
        EXPECT_EQ(500, sz1.getAr());
        EXPECT_EQ(654, sz1.getId());
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

    TEST(Szamlazas, Szamlaz)
        Ugyfel u0("Szió Mió", 126, 2005, 6);
        u0.setEgyenleg(1500);
        Szerzodes sz0(2003, 1, 29, u0, 300, 987);
        Date d0(2022, 2, 1);
        Date d1(2021, 10, 5);
        szamlaz(sz0, d1, d0);
        //EXPECT_TRUE(gtest_lite::almostEQ(310.0, sz0.getUgyfel().getEgyenleg()));
        EXPECT_EQ(310.0, sz0.getUgyfel().getEgyenleg());
    END


    TEST(Ugyfel, fogyasztas)
        Pr("Nem tudom mit kéne csinálni");
        Ugyfel u0;
        u0.setMiota(1);
        u0.fogyasztasBejelent(300);
        EXPECT_EQ(300.0, u0.getAvgFogyasztas());
        u0.setMiota(5);
        u0.fogyasztasBejelent(400);
        u0.fogyasztasBejelent(200);
        u0.fogyasztasBejelent(500);
        u0.fogyasztasBejelent(250);
        EXPECT_EQ(330.0, u0.getAvgFogyasztas());
        EXPECT_EQ(5, u0.getMiota());
    END

    std::cout << "Lab08-as halmaz tesztek:" << std::endl;
    TEST(int, insert) {
            Set<int> s0;
            s0.insert(1);
            s0.insert(2);
            EXPECT_TRUE(s0.isElement(1)) << "== Betettuk, de nincs benne! ==\n";
            EXPECT_TRUE(s0.isElement(2)) << "== Betettuk, de nincs benne! ==\n";
            EXPECT_FALSE(s0.isElement(0)) << "== Nem tettuk be, de benne van! ==\n";
            EXPECT_EQ(2, s0.size()) << "== Nem jo meretet! ***\n";
            s0.insert(1);
            EXPECT_EQ(2, s0.size()) << "== Azonos elem utan nem jo a meretet! ==\n";
        } ENDM

    /// kivétel dobás tesztelése int-re
    TEST(int, exception) {
            Set<int, 1> s0;
            EXPECT_NO_THROW(s0.insert(1));
            EXPECT_THROW(s0.insert(2), const char*);
        } ENDM

    /// insert és isElement tesztelése char-ra
    TEST(char, insert) {
            Set<char> s0;
            s0.insert('a');
            EXPECT_TRUE(s0.isElement('a'));
            EXPECT_FALSE(s0.isElement('b'));
        } ENDM

    /// insert és isElement tesztelése Integer-re
    /*
    TEST(Integer, insert) {
            Set<Integer> s0;
            s0.insert(Integer(1));
            EXPECT_TRUE(s0.isElement(Integer(1)));
            EXPECT_FALSE(s0.isElement(Integer(120)));
        } ENDM
    */

    /// insert és isElement tesztelése Ugyfél-re, amikor mindkét koordináta számít az összehasonlításban
    TEST(Ugyfel, insert) {
            Set<Ugyfel> s0;
            s0.insert(Ugyfel("Szió Mió", 126, 2005, 6));
            EXPECT_TRUE(s0.isElement(Ugyfel("Szió Mió", 126, 2005, 6)));
            EXPECT_FALSE(s0.isElement(Ugyfel("Helloka Belloka", 126, 2005, 6)));
            EXPECT_FALSE(s0.isElement(Ugyfel("Szió Mió", 126, 1999, 6)));
        } ENDM
    /// insert és isElement tesztelése Szerződés-re, amikor mindkét koordináta számít az összehasonlításban
    TEST(Szerzodes, insert) {
            Set<Szerzodes> s0;
            Ugyfel u0("Csá", 123, 2006, 3);
            s0.insert(Szerzodes(2003, 1, 29, u0, 300, 987));
            EXPECT_TRUE(s0.isElement(Szerzodes(2003, 1, 29, u0, 300, 987)));
            EXPECT_FALSE(s0.isElement(Szerzodes(1999, 05, 14, u0, 300, 987)));
            EXPECT_FALSE(s0.isElement(Szerzodes(2003, 1, 29, u0, 5, 456)));
        } ENDM
    /*
    TEST(Random, valami)
        std::cout << "Szia!" << std::endl;
    END
    */
    return 0;
}
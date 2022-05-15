#include <iostream>

#include "string5.h"
#include "mvm.h"
//#define MEMTRACE
//#include "memtrace.h"

#define MENU ///Ha a menürendszert szeretnénk futtatni
#define TESTESETEK /// Ha a teszteseteket szeretnénk futtatni

#ifdef TESTESETEK
#include "gtest_lite.h"
#endif

int main() {

    #ifdef TESTESETEK
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
        Ugyfel u0("Jancsi Jóska", 123, Date(2022), 3);
        Ugyfel u1(u0);
        String str("Hello bello");
        Ugyfel u2(str, 124, Date(1990), 4);
        EXPECT_STREQ("Jancsi Jóska", u0.getNevChar());
        EXPECT_EQ(123, u0.getId());
        EXPECT_EQ(Date(2022), u0.getDate());
        EXPECT_EQ(3, u0.getMiota());
        EXPECT_EQ(Ugyfel("Jancsi Jóska", 123, Date(2022), 3), u1);
        EXPECT_EQ(Ugyfel("Hello bello", 124, Date(1990), 4), u2);
    END
    TEST(Ugyfel, Input)
        Ugyfel u2/*("Helloka Belloka", 120, 2000, 15)*/;
        std::istringstream iss("Helloka Belloka\n120 2000 0 0");
        iss >> u2;
        EXPECT_STREQ("Helloka Belloka", u2.getNevChar());
        EXPECT_EQ(120, u2.getId());
        EXPECT_EQ(Date(2000), u2.getDate());
        EXPECT_EQ(0, u2.getMiota());
    END

    TEST(Ugyfel, befizet)
        /// Befizetés globális fv-vel
        Ugyfel u2("Helloka Belloka", 120, Date(2000), 15);
        u2.setEgyenleg(1500);
        befizet(u2, 300);
        EXPECT_EQ(1800, u2.getEgyenleg());

        /// Befizetés tagfv-vel
        u2.befizet(200);
        EXPECT_EQ(2000, u2.getEgyenleg());
    END

    TEST(Ugyfel, egyenlegLekerdez){
        Ugyfel u0("Enci Penci2", 124, Date(2013), 6);
        u0.setEgyenleg(500);
        EXPECT_EQ(500, egyenlegLekerdez(u0));
    }END

    TEST(Szerzodes, Konstruktor)
        Ugyfel u0("Enci Penci2", 124, Date(2013), 6);
        Szerzodes sz0(2003, 1, 29, 123, 300, 987);
        EXPECT_EQ(Date(2003, 1, 29), sz0.getDate());
        EXPECT_EQ(123, sz0.getUgyfel());
        EXPECT_EQ(300, sz0.getAr());
        EXPECT_EQ(987, sz0.getId());

        Date d0(2000, 8, 6);
        Szerzodes sz1(d0, 111, 500, 654);
        EXPECT_EQ(Date(2000, 8, 6), sz1.getDate());
        EXPECT_EQ(111, sz1.getUgyfel());
        EXPECT_EQ(500, sz1.getAr());
        EXPECT_EQ(654, sz1.getId());
    END

    TEST(Szamlazas, Szamlaz)
        Ugyfel u0("Szió Mió", 126, Date(2005), 6);
        u0.setEgyenleg(1500);
        Szerzodes sz0(2003, 1, 29, 126, 300, 987);
        Date d0(2022, 2, 1);
        Date d1(2021, 10, 5);
        Set<Ugyfel> set;
        set.insert(u0);
        EXPECT_NO_THROW(szamlaz(sz0, d1, d0, set));
        //EXPECT_TRUE(gtest_lite::almostEQ(310.0, sz0.getUgyfel().getEgyenleg()));
        EXPECT_EQ(310.0, set[0].getEgyenleg());
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

    Pr("Lab08-as halmaz tesztek:");
    /// Ezek a 8-adik laborból a halmazok tesztjei
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


    /// insert és isElement tesztelése Ugyfél-re, amikor mindkét koordináta számít az összehasonlításban
    TEST(Ugyfel, insert) {
            Set<Ugyfel> s0;
            s0.insert(Ugyfel("Szió Mió", 126, Date(2005, 0, 0), 6));
            EXPECT_TRUE(s0.isElement(Ugyfel("Szió Mió", 126, Date(2005, 0, 0), 6)));
            EXPECT_FALSE(s0.isElement(Ugyfel("Helloka Belloka", 126, Date(2005, 0, 0), 6)));
            EXPECT_FALSE(s0.isElement(Ugyfel("Szió Mió", 126, Date(1999, 0, 0), 6)));
        } ENDM
    /// insert és isElement tesztelése Szerződés-re, amikor mindkét koordináta számít az összehasonlításban
    TEST(Szerzodes, insert) {
            Set<Szerzodes> s0;
            s0.insert(Szerzodes(2003, 1, 29, 0, 300, 987));
            EXPECT_TRUE(s0.isElement(Szerzodes(2003, 1, 29, 0, 300, 987)));
            EXPECT_FALSE(s0.isElement(Szerzodes(1999, 05, 14, 0, 300, 987)));
            EXPECT_FALSE(s0.isElement(Szerzodes(2003, 1, 29, 0, 5, 456)));
    } ENDM

    TEST(Fálj, kezelés)
        Ugyfel u0("Vicc Elek", 1, Date(2022, 5, 9));
        //ASSERT_NO_THROW(std::cout << u0;)
        Szerzodes sz0(Date(), 0, 11, 12);
        //ASSERT_NO_THROW(std::cout << sz0;)
        Set<Ugyfel> s0;
        s0.insert(u0);
        s0.insert(Ugyfel("Helloka", 123, Date()));
        Set<Szerzodes> s1;
        s1.insert(sz0);
        s1.insert(Szerzodes());
        fileKiir(s0, s1);
        Set<Ugyfel> s2;
        EXPECT_NO_THROW(s2 = ugyfelekBeolvas());
        Pr(s2[0] << s2[1]);

        Set<Szerzodes> s3;
        EXPECT_NO_THROW(s3 = szerzodesekBeolvas());
        Pr(s3[0] << s3[1]);
    END

#endif //TESTESETEK
    // Itt a vége ha a teszteseteket futtatjuk

    ///A használható menürendszer:
#ifdef MENU

    String opcio;

    Set<Ugyfel> ugyfelek;
    ugyfelek = ugyfelekBeolvas();
    Set<Szerzodes> szerzodesek;
    szerzodesek = szerzodesekBeolvas();

    std::cout << "HVM nyilvántartórendszer:" << std::endl;
    std::cout << "Ügyfél adatinak felvétele:\t [uj]\n"
        << "szolgáltatási szerződés kötése:\t [uj]\n"
         <<"Szerződések kiírása:\t\t [ki]\n"
        << "Ügyfelek kiírása:\t\t [ki]\n"
        << "szolgáltatási díj előírása:\t [szamla]\n"
        << "szolgáltatási díj befizetése:\t [bef]\n"
        << "Ügyfél egyenleg lekérdezése:\t [el]\n"
        << "Fogyasztás bejelentése:\t\t [bf]\n"
        << "Kilépés: \t\t\t [q]/[exit]"
        << std::endl;

    while(true) {
        String al;
        std::cout << ">>";
        std::cin >> opcio;
        if(std::cin.fail()){
            std::cout << "Nem megfelelő formátum" << std::endl;
            std::cin.clear();
            continue;
        }
        //std::cout << opcio << std::endl;


        if (opcio == "uj") {
            std::cout << "mit?" << std::endl <<  ">>";
            std::cin >> al;
            if (al == "u"){
                Ugyfel u;
                std::cin >> u;
                if(std::cin.fail()){
                    std::cout << "Nem megfelelő formátum" << std::endl;
                    std::cin.clear();
                    continue;
                }
                ugyfelek.insert(u);
            }
            else if (al == "sz") {
                //std::cout << "Új szerződés:" << std::endl;
                Szerzodes sz;
                std::cin >> sz;
                if(std::cin.fail()){
                    std::cout << "Nem megfelelő formátum" << std::endl;
                    std::cin.clear();
                    continue;
                }
                szerzodesek.insert(sz);
            }
            else
                std::cout << "Argumentumok hiányoznak az \"uj\"-hoz" << std::endl;
        }
        if (opcio == "ki") {
            std::cout << "mit?" << std::endl <<  ">>";
            std::cin >> al;
            if (al == "u"){
                if (ugyfelek.size() == 0) {
                    std::cout << "Nincs tárolt elem";
                    continue;
                }
                for (int i = 0; i < ugyfelek.size(); ++i) {
                    std::cout << ugyfelek[i];
                }
            }
            else if (al == "sz") {
                if (szerzodesek.size() == 0) {
                    std::cout << "Nincs tárolt elem";
                    continue;
                }
                for (int i = 0; i < szerzodesek.size(); ++i) {
                    std::cout << szerzodesek[i];
                }
            }
            else
                std::cout << "Argumentumok hiányoznak az \"uj\"-hoz" << std::endl;
        }
        else if(opcio == "szamla"){
            int az;
            Date mettol, meddig;
            std::cout << "Szerződés azonosító: ";
            std::cin >> az;
            if(std::cin.fail()){
                std::cout << "Nem megfelelő azonosító" << std::endl;
                std::cin.clear();
                continue;
            }
            std::cout << "Mettől: ";
            std::cin >> mettol;
            std::cout << "Meddig: ";
            std::cin >> meddig;
            if(std::cin.fail()) {
                std::cout << "Nem megfelelő bemenet";
                std::cout.clear();
                continue;
            }
            Szerzodes sz;
            int sorszam = szerzodesek.lookup(az);
            if(sorszam < 0){
                std::cout << "Nincs ilyen szerződés" << std::endl;
                continue;
            }
            sz = szerzodesek[sorszam];
            try {
                szamlaz(sz, mettol, meddig, ugyfelek);
            }
            catch (std::out_of_range&){
                std::cout << "Nincs ilyen ügyfél";
            }
        }
        else if(opcio == "bef"){
            //std::cout << "befizet, parancs: " << opcio << std::endl;
            int az;
            double osszeg;
            std::cout << "Ügyfél formátum: ";
            std::cin >> az;
            if(std::cin.fail()){
                std::cout << "Nem megfelelő azonosító" << std::endl;
                std::cin.clear();
                continue;
            }
            std::cout << "Befizetett összeg: ";
            std::cin >> osszeg;
            if(std::cin.fail()){
                std::cout << "Nem megfelelő formátum" << std::endl;
                std::cin.clear();
                continue;
            }
            Ugyfel u;
            int sorszam = ugyfelek.lookup(az);
            if(sorszam < 0){
                std::cout << "Nincs ilyen ügyfél" << std::endl;
                continue;
            }
            //u = ugyfelek[sorszam];
            befizet(ugyfelek[sorszam], osszeg);
        }
        else if(opcio == "el"){
            //std::cout << "egyenleg lekérdez, parancs: " << opcio << std::endl;
            int az;
            std::cout << "Ügyfél azonosító: ";
            std::cin >> az;
            if(std::cin.fail()){
                std::cout << "Nem megfelelő azonosító" << std::endl;
                std::cin.clear();
                continue;
            }
            Ugyfel u;
            int sorszam = ugyfelek.lookup(az);
            if(sorszam < 0){
                std::cout << "Nincs ilyen ügyfél" << std::endl;
                continue;
            }
            u = ugyfelek[sorszam];
            std::cout << "A " << az << " szamú ügyfél egyenlege: " << egyenlegLekerdez(u) << std::endl;
        }
        else if(opcio == "bf"){
            //std::cout << "fogyasztas lekerdez, parancs: " << opcio << std::endl;
            int az;
            double fogyasztas;
            std::cout << "Ügyfél azonosító: ";
            std::cin >> az;
            if(std::cin.fail()){
                std::cout << "Nem megfelelő azonosító" << std::endl;
                std::cin.clear();
                continue;
            }
            std::cout << "Fogyasztas: ";
            std::cin >> fogyasztas;
            if(std::cin.fail()){
                std::cout << "Nem megfelelő formátum" << std::endl;
                std::cin.clear();
                continue;
            }
            Ugyfel u;
            int sorszam = ugyfelek.lookup(az);
            if(sorszam < 0){
                std::cout << "Nincs ilyen ügyfél" << std::endl;
                continue;
            }
            //u = ugyfelek[sorszam];
            ugyfelek[sorszam].fogyasztasBejelent(fogyasztas);
            std::cout << "A " << sorszam << " szamú ügyfél új fogyasztása: " << fogyasztas;

        }
        else if (opcio == "q" || opcio == "exit") {
            fileKiir(ugyfelek, szerzodesek);
            std::cout << "Kilépés" << std::endl;
            return 0;
        }
        else
            std::cout << "Ismeretlen parancs: " << opcio << std::endl;
    }

#endif //MENU


}
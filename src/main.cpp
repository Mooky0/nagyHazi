#include <iostream>

#include "gtest_lite.h"
#include "mvm.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    TEST(Datumteszt, Konstruktor)
        Date d0(2022, 4, 14);
        ASSERT_NO_THROW(std::cout << d0;)
        Date d1;
        ASSERT_NO_THROW(std::cout << d1;)
    END


    TEST(Ugyfel, Konstruktor)
        Ugyfel u0("Jancsi Jóska", 123, 2022, 3);
        Ugyfel u1(u0);
        std::string str = "Hello bello";
        Ugyfel u2(str, 124, 1990, 4);
        ASSERT_NO_THROW(std::cout << u0);
        ASSERT_NO_THROW(std::cout << u1)
        ASSERT_NO_THROW(std::cout << u2);
    END
    TEST(Ugyfel, Input)
        Ugyfel u2;
        std::istringstream iss("Helloka Belloka\n120 2000 15");
        iss >> u2;
        EXPECT_EQ("Helloka Belloka", u2.getNev());
        EXPECT_EQ(120, u2.getId());
        EXPECT_EQ(2000, u2.getSzulEv());
        EXPECT_EQ(15, u2.getMiota());
    END

    TEST(Szerzodes, Konstruktor)
        Ugyfel u2("Enci Penci", 124, 2013, 6);
        Szerzodes sz0(2003, 1, 29, u2, 300, 987);
        ASSERT_NO_THROW(std::cout << sz0);
    END

    return 0;
}

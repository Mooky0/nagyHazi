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

    TEST(Szerzodes, Konstruktor)
        Szerzodes sz0(2003, 1, 29);
    END

    TEST(Ugyfel, Konstruktor)
        Ugyfel u0("Jancsi Jóska", 123, 2022, 3);
        Ugyfel u1(u0);
        ASSERT_NO_THROW(std::cout << u0);
        ASSERT_NO_THROW(std::cout << u1);
    END

    return 0;
}

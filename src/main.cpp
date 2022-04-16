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
        Ugyfel u0("Jancsi Jóska", 0, 2022);

    END

    return 0;
}

#ifndef UNITUSEDBOOKTEST_H
#define UNITUSEDBOOKTEST_H

#include "Used_Book.h"
#include <iostream>

class UnitTestUsedBook {
public:
    void RunTests() {
        testUsedBookClass();
    }

private:
    void testUsedBookClass() {
        Used_Book usedBook("Used Title", "Used Author", "Used Genre", 4.5, 10, 19.99, "Good", true);

        // Test constructor and getters
        if (usedBook.get_title() == "Used Title" &&
            usedBook.get_author() == "Used Author" &&
            usedBook.get_genre() == "Used Genre" &&
            usedBook.get_rating() == 4.5 &&
            usedBook.get_quantity() == 10 &&
            usedBook.get_condition() == "Good" &&
            usedBook.get_available() == true) {
            std::cout << "Constructor and getters: Passed" << std::endl;
        } else {
            std::cout << "Constructor and getters: Failed" << std::endl;
        }

        // Test get_used_price
        float expectedUsedPrice = 19.99 - 6; // Assuming 6 is subtracted in get_used_price
        if (usedBook.get_used_price() == expectedUsedPrice) {
            std::cout << "get_used_price: Passed" << std::endl;
        } else {
            std::cout << "get_used_price: Failed" << std::endl;
        }

        // Test display
        std::cout << "Display Function Output:" << std::endl;
        usedBook.display();

        // Test get_type
        if (usedBook.get_type() == "Used") {
            std::cout << "get_type: Passed" << std::endl;
        } else {
            std::cout << "get_type: Failed" << std::endl;
        }
    }
};

#endif

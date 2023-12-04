#ifndef UNITPHYSICALBOOKTEST_H
#define UNITPHYSICALBOOKTEST_H

#include "Physical_Book.h"
#include <iostream>

class UnitTestPhysicalBook {
public:
    void RunTests() {
        testPhysicalBookClass();
    }

private:
    void testPhysicalBookClass() {
        Physical_Book physicalBook("Physical Title", "Physical Author", "Physical Genre", 4.5, 10, 19.99, true);

        // Test constructor and getters
        if (physicalBook.get_title() == "Physical Title" &&
            physicalBook.get_author() == "Physical Author" &&
            physicalBook.get_genre() == "Physical Genre" &&
            physicalBook.get_rating() == 4.5 &&
            physicalBook.get_quantity() == 10 &&
            physicalBook.get_availability() == true) {
            std::cout << "Constructor and getters: Passed" << std::endl;
        } else {
            std::cout << "Constructor and getters: Failed" << std::endl;
        }

        // Test get_Phys_price
        float expectedPhysPrice = 19.99 + 5; // Assuming 5 is added in get_Phys_price
        if (physicalBook.get_Phys_price() == expectedPhysPrice) {
            std::cout << "get_Phys_price: Passed" << std::endl;
        } else {
            std::cout << "get_Phys_price: Failed" << std::endl;
        }

        // Test display
        std::cout << "Display Function Output:" << std::endl;
        physicalBook.display();
        cout << "\n" << endl;

        // Test get_type
        if (physicalBook.get_type() == "Physical") {
            std::cout << "get_type: Passed" << std::endl;
        } else {
            std::cout << "get_type: Failed" << std::endl;
        }
    }
};

#endif

#ifndef UNITDIGITALTEST_H
#define UNITDIGITALTEST_H

#include "Digital_Book.h"
#include <iostream>

class UnitTestDigitalBook {
public:
    void RunTests() {
        testDigitalBookClass();
    }

private:
    void testDigitalBookClass() {
        Digital_Book digitalBook("Digital Title", "Digital Author", "Digital Genre", 4.5, 10, 19.99, "Digital Platform");

        // Test constructor and getters
        if (digitalBook.get_title() == "Digital Title" &&
            digitalBook.get_author() == "Digital Author" &&
            digitalBook.get_genre() == "Digital Genre" &&
            digitalBook.get_rating() == 4.5 &&
            digitalBook.get_quantity() == 10 &&
            digitalBook.get_price() == 19.99 &&
            digitalBook.get_platform() == "Digital Platform") {
            std::cout << "Constructor and getters: Passed" << std::endl;
        } else {
            std::cout << "Constructor and getters: Failed" << std::endl;
        }

        // Test set_platform and get_platform
        digitalBook.set_platform("New Platform");
        if (digitalBook.get_platform() == "New Platform") {
            std::cout << "set_platform and get_platform: Passed" << std::endl;
        } else {
            std::cout << "set_platform and get_platform: Failed" << std::endl;
        }

        // Test get_digital_price
        float expectedDigitalPrice = 19.99 - 3.5; // Assuming 3.5 is subtracted in get_digital_price
        if (digitalBook.get_digital_price() == expectedDigitalPrice) {
            std::cout << "get_digital_price: Passed" << std::endl;
        } else {
            std::cout << "get_digital_price: Failed" << std::endl;
        }

        // Test display
        std::cout << "Display Function Output:" << std::endl;
        digitalBook.display();

        // Test get_type
        if (digitalBook.get_type() == "Digital") {
            std::cout << "get_type: Passed" << std::endl;
        } else {
            std::cout << "get_type: Failed" << std::endl;
        }
    }
};

#endif

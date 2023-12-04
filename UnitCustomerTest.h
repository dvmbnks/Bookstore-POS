#ifndef UNITCUSTOMERTEST_H
#define UNITCUSTOMERTEST_H

#include "Customer.h"
#include <iostream>

class UnitTestCustomer {
public:
    void RunTests() {
        testCustomerClass();
    }

private:
    void testCustomerClass() {
        Customer customer("John Doe", 1234567890, "john@example.com");

        // Test constructor and getters
        if (customer.get_name() == "John Doe" &&
            customer.get_phone() == 1234567890 &&
            customer.get_email() == "john@example.com") {
            std::cout << "Constructor and getters: Passed" << std::endl;
        } else {
            std::cout << "Constructor and getters: Failed" << std::endl;
        }

        // Test default constructor
        Customer defaultCustomer;
        if (defaultCustomer.get_name() == "" &&
            defaultCustomer.get_phone() == 0 &&
            defaultCustomer.get_email() == "") {
            std::cout << "Default constructor: Passed" << std::endl;
        } else {
            std::cout << "Default constructor: Failed" << std::endl;
        }

        // Test getters
        if (customer.get_name() == "John Doe" &&
            customer.get_phone() == 1234567890 &&
            customer.get_email() == "john@example.com") {
            std::cout << "Getters: Passed" << std::endl;
        } else {
            std::cout << "Getters: Failed" << std::endl;
        }

        int customerID = customer.get_ID();
        if (customerID != 0) {
            std::cout << "get_ID: Passed" << std::endl;
        } else {
            std::cout << "get_ID: Failed" << std::endl;
        }
    }
};

#endif

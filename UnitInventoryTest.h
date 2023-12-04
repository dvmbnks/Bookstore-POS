#ifndef UNITINVENTORYTEST_H
#define UNITINVENTORYTEST_H

#include "Inventory.h"
#include "Physical_Book.h"
#include "Digital_Book.h"
#include "Used_Book.h"
#include <iostream>

class UnitTestInventory {
public:
    void RunTests() {
        testInventoryClass();
    }

private:
    void testInventoryClass() {
        Inventory inventory;

        // Test search_book
        Book* foundBook = inventory.search_book("Book Title");
        if (foundBook != nullptr) {
            std::cout << "search_book: Passed" << std::endl;
            delete foundBook; // Free the dynamically allocated book
        } else {
            std::cout << "search_book: Failed" << std::endl;
        }

        // Test update_book (assume that the book "Book Title" exists)
        inventory.update_book("Book Title");

        // Test listing all books
        std::cout << "List of Books in Inventory:" << std::endl;
        //inventory.list_books();

        // You can add more test cases for other methods as needed.
    }
};

#endif

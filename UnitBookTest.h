#ifndef UNITBOOKTEST_H
#define UNITBOOKTEST_H

#include "Book.h"
#include <iostream>
#include <sstream>

class UnitTestBook {
public:
    void RunTests() {
        testBookClass();
    }

private:
    void testBookClass() {
        Book book("Title", "Author", "Genre", 4.5, 10, 19.99);

        // Test constructor and getters
        if (book.get_title() == "Title" &&
            book.get_author() == "Author" &&
            book.get_genre() == "Genre" &&
            book.get_rating() == 4.5 &&
            book.get_quantity() == 10 &&
            book.get_price() == 19.99) {
            std::cout << "Constructor and getters: Passed" << std::endl;
        } else {
            std::cout << "Constructor and getters: Failed" << std::endl;
        }

        // Test setters and getters
        book.set_title("New Title");
        if (book.get_title() == "New Title") {
            std::cout << "Setters and getters: Passed" << std::endl;
        } else {
            std::cout << "Setters and getters: Failed" << std::endl;
        }

        book.set_author("New Author");
        if (book.get_author() == "New Author") {
            std::cout << "Setters and getters: Passed" << std::endl;
        } else {
            std::cout << "Setters and getters: Failed" << std::endl;
        }

        book.set_genre("New Genre");
        if (book.get_genre() == "New Genre") {
            std::cout << "Setters and getters: Passed" << std::endl;
        } else {
            std::cout << "Setters and getters: Failed" << std::endl;
        }

        book.set_rating(3.2);
        if (book.get_rating() == 3.2) {
            std::cout << "Setters and getters: Passed" << std::endl;
        } else {
            std::cout << "Setters and getters: Failed" << std::endl;
        }

        book.set_quantity(15);
        if (book.get_quantity() == 15) {
            std::cout << "Setters and getters: Passed" << std::endl;
        } else {
            std::cout << "Setters and getters: Failed" << std::endl;
        }

        book.set_price(29.99);
        if (book.get_price() == 29.99) {
            std::cout << "Setters and getters: Passed" << std::endl;
        } else {
            std::cout << "Setters and getters: Failed" << std::endl;
        }

        // Test get_type
        if (book.get_type() == "Book") {
            std::cout << "get_type: Passed" << std::endl;
        } else {
            std::cout << "get_type: Failed" << std::endl;
        }
    }
};

#endif
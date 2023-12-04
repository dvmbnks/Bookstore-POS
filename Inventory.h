#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <vector>
#include "Book.h"
#include "Digital_Book.h"
#include "Physical_Book.h"
#include "Used_Book.h"

class Inventory {
public:
    Inventory();
    void add_physical_book(const Physical_Book &book);
    void add_digital_book(Digital_Book& book);
    void add_used_book(Used_Book& book);
    void remove_physical_book(Physical_Book& book);
    void remove_digital_book(Digital_Book& book);
    void remove_used_book(Used_Book& book);
    void remove_book_from_all(Book& book);
    Book* search_book(std::string title);
    void list_books();
    void update_book(std::string title);
    void save_to_file(string filename);

private:
    std::vector<Physical_Book> physical_books;
    std::vector<Digital_Book> digital_books;
    std::vector<Used_Book> used_books;
    std::vector<Book> all_books;
};

#endif

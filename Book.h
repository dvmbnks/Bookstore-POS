#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
#include <ctime>

using namespace std;


class Book{
    public:
    string title;
    string author;
    string genre;
    float rating; // Rating should be out of 10
    time_t date;
    int quantity;
    float price;


    Book(string title, string author, string genre, float rating, int quantity, float price);
    Book();

    int get_quantity();
    float get_price();
    string get_title();
    string get_author();
    string get_genre();
    float get_rating();
    time_t get_date();

    void set_quantity(int quantity);
    void set_title(string title);
    void set_price(float price);
    void set_author(string author);
    void set_genre(string genre);
    void set_rating(float rating);

    

    virtual void display(); // virtual function
    virtual string get_type();

};


#endif

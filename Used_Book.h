#ifndef USEDBOOK_H
#define USEDBOOK_H

#include "Physical_Book.h"
using namespace std;

class Used_Book : public Physical_Book {
    private:
    bool available;
    string condition;
    float used_price;
    string type;

    public:
    Used_Book();
    Used_Book(string title, string author, string genre, float rating, int quantity, float price, string condtion, bool available);

    string get_type() override;
    bool get_available();
    string get_condition();
    float get_used_price();

    void display() override;
};

#endif
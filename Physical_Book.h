#ifndef PHYSICALBOOK_H
#define PHYSICALBOOK_H
#include "Book.h"
#include <string>
using namespace std;

class Physical_Book : public Book{
    private:
    bool availability;
    float physical_price;
    string type;

    public:
    Physical_Book();
    Physical_Book(string title, string author, string genre, float rating, int quantitiy, float price, bool availabilty);

    string get_condition();
    bool get_borrowed();
    bool get_availability();
    float get_Phys_price();
    string get_type() override;

    void set_physical_price(float price);
    void set_availability(bool availability);

    void display() override; 

};

#endif
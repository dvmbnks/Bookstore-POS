#ifndef DIGITALBOOK_H
#define DIGITALBOOK_H
#include "Book.h"

class Digital_Book : public Book{
    private:
    string platform;
    float digital_price;
    string type;
    public:
    Digital_Book();
    Digital_Book(string title, string author, string genre, float rating, int quantity, float price, string platform);

    string get_platform();
    float get_digital_price();
    string get_type() override;

    void set_platform(string platform);
    void set_digital(float digital_price);
    

    void display() override;
    
};

#endif
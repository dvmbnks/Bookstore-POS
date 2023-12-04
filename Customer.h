#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
using namespace std;

class Customer{
    private:
    string name;
    int phone;
    string email;

    protected:
    int ID;

    public:
    Customer();
    Customer(string name, int phone, string email);
    string get_name();
    string get_email();
    int get_phone();
    int get_ID();
    
};

#endif
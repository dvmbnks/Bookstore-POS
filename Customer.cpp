#include "Customer.h"

Customer::Customer(string name, int phone, string email){
    this -> name = name;
    this -> phone = phone;
    this -> email = email;
}
Customer::Customer(){
    name = "";
    phone = 0;
    email = "";
}

string Customer::get_name(){
    return name;
}
string Customer::get_email(){
    return email;
}
int Customer::get_phone(){
    return phone;

}
int Customer::get_ID(){
    return ID;

}
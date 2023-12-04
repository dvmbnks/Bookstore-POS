#include "Physical_Book.h"
#include "Book.h"

Physical_Book::Physical_Book(){
    availability = false;
    physical_price = 0;
}

Physical_Book::Physical_Book(string title, string author, string genre, float rating, int quantity, float price, bool availabilty){
    this -> title = title;
    this -> author = author;
    this -> genre = genre;
    this -> rating = rating;
    this -> quantity = quantity;
    this -> availability = availabilty;
    this -> price = price;
    this -> physical_price = get_Phys_price();
}

void Physical_Book::display(){
    cout << "Title : " << get_title() << "\n";
    cout << "Author : " << get_author() << "\n";
    cout << "Genre : " << get_genre()<< "\n";
    cout << "Rating : " << get_rating() << "\n";
    cout << "Quantity : " << get_quantity() << "\n";
    cout << "Available: " << get_availability() << "\n";
    cout << "Price: $" << get_Phys_price() << "\n";
    cout << "__________________________________";
    
}
string Physical_Book::get_type(){
    return "Physical";
}

bool Physical_Book::get_availability(){
    return availability;
}
float Physical_Book::get_Phys_price(){
    return (price+5);
}

void Physical_Book::set_physical_price(float physical_price){
    this -> physical_price = physical_price;
}
void Physical_Book::set_availability(bool availability){
    this-> availability = availability;
}



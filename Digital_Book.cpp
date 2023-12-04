#include "Book.h"
#include "Digital_Book.h"

Digital_Book::Digital_Book(){
    platform = "";
    digital_price = 0;
}
Digital_Book::Digital_Book(string title, string author, string genre, float rating, int quantity, float price, string platform){
    this -> title = title;
    this -> author = author;
    this -> genre = genre;
    this -> rating = rating;
    this -> quantity = quantity;
    this -> price = price;
    this -> platform = platform;
    this -> digital_price = digital_price;
}

string Digital_Book::get_platform(){
    return platform;
}

float Digital_Book::get_digital_price(){
    float price_d = get_price();
    price_d = price_d - 3.5;
    digital_price = price_d;
    return digital_price;
}
void Digital_Book::display(){
    cout << "Title : " << get_title() << "\n";
    cout << "Author : " << get_author() << "\n";
    cout << "Genre : " << get_genre()<< "\n";
    cout << "Rating : " << get_rating() << "\n";
    cout << "Quantity : " << get_quantity() << "\n";
    cout << "Price: " << get_digital_price() << "\n";
    cout << "Platform: " << get_platform() << "\n";
}

void Digital_Book::set_platform(string platform){
    this -> platform = platform;
}

void Digital_Book::set_digital(float digital_price){
    this -> digital_price = digital_price;
    
}

string Digital_Book::get_type(){
    return "Digital";

}

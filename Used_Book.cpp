#include "Used_Book.h"

Used_Book::Used_Book(){
    available = false;
    used_price = 0;
    condition = "";
}
Used_Book::Used_Book(string title, string author, string genre, float rating, int quantity, float price, string condition, bool available)
{
    this -> title = title;
    this -> author = author;
    this -> genre = genre;
    this -> rating = rating;
    this -> quantity = quantity;
    this -> price = price;
    this->condition = condition;
    this->available = available;
    this->used_price = price;
}

float Used_Book::get_used_price()
{
    float base_price = get_price(); // Get the base price using the base class method
    float price_u = base_price - 6; // Apply your calculation
    used_price = price_u;
    return used_price;
}

string Used_Book::get_condition(){
    return condition;
}
string Used_Book::get_type(){
    return "Used";

}

bool Used_Book::get_available(){
    return available;
}
void Used_Book::display() {
    cout << "Title: " << get_title() << "\n";
    cout << "Author: " << get_author() << "\n";
    cout << "Genre: " << get_genre() << "\n";
    cout << "Rating: " << get_rating() << "\n";
    cout << "Quantity: " << get_quantity() << "\n";
    cout << "Condition: " << get_condition() << "\n";
    cout << "Available: " << get_available() << "\n";
    cout << "Used Book Price: $" << get_used_price() << "\n";
    cout << "_____________________" << "\n";
}


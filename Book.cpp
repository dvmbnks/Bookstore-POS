#include "Book.h"
#include <iostream>
using namespace std;

Book::Book(string title, string author, string genre, float rating, int quantity, float price){
    this -> title = title;
    this -> author = author;
    this -> genre = genre;
    this -> rating = rating;
    this -> quantity = quantity;
    this -> price = price;
}
Book::Book(){
    title = "";
    author = "";
    genre = "";
    quantity = 0;
    rating = 0;
    price = 0;
}

string Book::get_title() {
    return title;
}
int Book::get_quantity(){
    return quantity;
}
float Book::get_price(){
    return price;
}

string Book::get_author() {
    return author;
}

string Book::get_genre() {
    return genre;
}
float Book::get_rating() {
    return rating;
}
void Book::display(){
    cout << "Title : " << title << "\n";
    cout << "Author : " << author << "\n";
    cout << "Genre : " << genre << "\n";
    cout << "Rating : " << rating << "\n";
    cout << "Quantity : " << quantity << "\n";
    cout << "Price: $" << price << "\n";
    cout << "__________________________________" << "\n";
}

void Book::set_quantity(int quantity){
    this -> quantity = quantity;
}
void Book::set_title(string title){
    this -> title = title;

}
void Book::set_price(float price){
    this -> price = price;

}
void Book::set_author(string author){
    this -> author = author;

}
void Book::set_genre(string genre){
    this -> genre = genre;

}
void Book::set_rating(float rating){
    this -> rating = rating;
}

time_t Book::get_date() {
    return date;
}

string Book::get_type(){
    return "Book";
}

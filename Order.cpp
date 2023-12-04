#include "Order.h"
#include "Inventory.h"
#include "Book.h"
#include "Digital_Book.h"
#include "Physical_Book.h"
#include "Used_Book.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

// Constructor for creating an order
Order::Order(string type, string orderId, float totalPrice, string orderStatus, Book* book, int quantity) {
    this->type = type;
    this->order_id = orderId; // Changed the attribute name
    this->total_price = totalPrice;
    this->order_status = orderStatus;
    this->book = book;
    this->quantity = quantity;
}

// Default constructor
Order::Order(){
    type = "";
    order_id = "";
    total_price = 0.0;
    order_status = "";
    book = nullptr;
    quantity = 0;

}

// Process a sale by reducing the quantity of the ordered book in the inventory
// Process a sale by reducing the quantity of the ordered book in the inventory
void Order::process_sale(Inventory& inventory, string title) {
    if (book && quantity > 0) {
        Book* inventoryBook = inventory.search_book(title);

        if (inventoryBook) {
            if (inventoryBook->get_quantity() >= quantity) {
                inventoryBook->set_quantity(inventoryBook->get_quantity() - quantity);
                order_status = "Completed";
                
                ifstream inputFile("book2.txt");
                ofstream outputFile("temp.txt");

                string line;
                while (getline(inputFile, line)) {
                    istringstream iss(line);
                    string currentTitle;

                    // Extract the title from the line
                    if (getline(iss, currentTitle, ',')) {
                        if (currentTitle == title) {
                            // Update this line with the new book information
                            outputFile << inventoryBook->get_title() << ","
                                    << inventoryBook->get_author() << ","
                                    << inventoryBook->get_genre() << ","
                                    << inventoryBook->get_rating() << ","
                                    << inventoryBook->get_quantity() << ","
                                    << inventoryBook->get_price() << "\n";
                        } else {
                            // Keep other lines unchanged
                            outputFile << line << "\n";
                        }
                    }
                }

                inputFile.close();
                outputFile.close();

                // Rename the temporary file to replace the original
                remove("book2.txt");
                rename("temp.txt", "book2.txt");

                // Determine the book type
                string typeBook = inventoryBook -> get_type(); // Get the class type

                // Use if statements to get the price based on the book type
                float newPrice = 0.0;

                if (typeBook == "Physical") {
                    newPrice = inventoryBook->get_price() + 5;
                } else if (typeBook == "Digital") {
                    newPrice = inventoryBook->get_price() - 3.5;
                } else if (typeBook == "Used") {
                    newPrice = inventoryBook->get_price() - 6;
                }
                else{
                    newPrice = inventoryBook->get_price();
                }

                total_price = total_price + quantity * newPrice;
                cout << "Order processed successfully." << endl;
                set_total_price(total_price);
            } else {
                order_status = "Insufficient Stock";
                cout << "Order could not be processed due to insufficient stock." << endl;
            }
        } else {
            order_status = "Book Not Found";
            cout << "The requested book was not found in the inventory." << endl;
        }
    }
}



// Getters and setter for order attributes
string Order::get_type() {
    return type;
}

string Order::get_order_id() {
    srand(42);

    int randomNumber = rand();

    int newRandomNumber;
    do {
        newRandomNumber = rand();
    } while (newRandomNumber == randomNumber);
    order_id = to_string(newRandomNumber);
    return order_id;
}

float Order::get_total_price() {
    return total_price;
}

void Order::set_total_price(float total_price) {
    this->total_price = total_price;
}

string Order::get_order_status() {
    return order_status;
}

Book* Order::get_book() {
    return book;
}

int Order::get_quantity() {
    return quantity;
}
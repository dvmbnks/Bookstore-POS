#ifndef ORDER_H
#define ORDER_H

#include "Inventory.h"
#include "Book.h"
#include <string>

class Order {
public:
    Order(std::string type, std::string orderId, float totalPrice, std::string orderStatus, Book* book, int quantity);
    Order();  // Default constructor

    // Getters and setter for order attributes
    std::string get_type();
    std::string get_order_id(); // Changed the method name
    float get_total_price();
    std::string get_order_status();
    Book* get_book();
    int get_quantity();
    void set_total_price(float total_price); // Added the correct method signature

    void process_sale(Inventory& inventory, string title);

private:
    std::string type;
    std::string order_id; // Changed the attribute name
    float total_price;
    std::string order_status;
    Book* book;
    int quantity;
};

#endif
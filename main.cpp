#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>  // Include vector for managing customers

#include "Book.h"
#include "Customer.h"  // Include the Customer class
#include "Digital_Book.h"
#include "Inventory.h"
#include "Order.h"
#include "Physical_Book.h"
#include "Used_Book.h"

using namespace std;

// Function to display the main menu
void display_menu() {
  cout << "======== Menu ========\n";
  cout << "1. Inventory\n";
  cout << "2. Process Sale\n";
  cout << "3. Manage Customers\n";  // Added option to manage customers
  cout << "4. Exit\n";              // Adjusted for new feature
  cout << "=======================\n";
}

// Define a function to display the inventory menu
void display_inventory_menu() {
  cout << "======== Inventory Menu ========\n";
  cout << "1. View Inventory\n";
  cout << "2. Update Book\n";
  cout << "3. Return to Main Menu\n";
  cout << "==============================\n";
}

// Function to display the customer management menu
void display_customer_menu() {
  cout << "======== Customer Management ========\n";
  cout << "1. Add Customer\n";
  cout << "2. View Customers\n";
  cout << "3. Return to Main Menu\n";
  cout << "=====================================\n";
}

int main() {
  // Create an inventory
  Inventory inventory;
  vector<Customer> customers;  // Store customers in a vector

  // Menu loop
  while (true) {
    display_menu();

    int choice;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
      int choice2;
      cout << "Would you like to View (1) or Edit (2)?: ";
      cin >> choice2;
      if (choice2 == 1) {
        cout << "\nCurrent Inventory:\n";
        inventory.list_books();
        cout << "\n";
      } else if (choice2 == 2) {
        string title2;
        cout << "Book you would like to edit [Enter Title]: ";
        cin.ignore();  // Clear the newline character
        getline(cin,
                title2);  // Use getline to read the entire title

        Book *bookToUpdate = inventory.search_book(title2);

        if (bookToUpdate != nullptr) {
          inventory.update_book(title2);
          delete bookToUpdate;
        } else {
          cout << "\n";
          cout << "!!!! Book does not exist in this Inventory !!!!\n";
          cout << "\n";
        }
      }
    } else if (choice == 2) {
      string title;
      int quantity = 0;
      float total_cost = 0.0;
      char buy_more;

      do {
        cout << "Enter the title of the book you want to purchase: ";
        cin.ignore();  // Clear the newline character from the previous input
        getline(cin,
                title);  // Use getline to read the entire title

        Book *bookToPurchase = inventory.search_book(title);

        if (bookToPurchase != nullptr) {
          bookToPurchase->display();
          cout << "\n" << endl;

          cout << "Enter the quantity: ";
          cin >> quantity;

          if (bookToPurchase->get_quantity() < quantity) {
            cout << "Not enough quantity in stock. Available: "
                 << bookToPurchase->get_quantity() << endl;
          } else {
            Order order1;
            string order_id = order1.get_order_id();
            Order order("Purchase", order_id, 0.0, "Pending", bookToPurchase,
                        quantity);
            order.process_sale(inventory, title);
            total_cost = total_cost + order.get_total_price();

            cout << "Total cost for this order: $" << order.get_total_price()
                 << endl;
          }

          cout << "Do you want to buy more books (Y/N)? ";
          cin >> buy_more;

          delete bookToPurchase;
        } else {
          cout << "!!!! Book does not exist in this Inventory !!!!\n";
          break;
        }
      } while (buy_more == 'Y' || buy_more == 'y');

      cout << "Total cost for all orders: $" << total_cost << endl;
    }

    else if (choice == 3) {
      // Customer management
      while (true) {
        display_customer_menu();
        int customerChoice;
        cout << "Enter your choice: ";
        cin >> customerChoice;

        if (customerChoice == 1) {
          // Add a customer
          string customerName;
          int customerPhone;
          string customerEmail;
          while (true) {
            cout << "Enter customer name: ";
            cin >> customerName;
            break;
            if (!customerName.empty()) {
              break;  // Exit the loop if a non-blank input is provided
            }
            cout << "Name cannot be blank. Please enter a valid name." << endl;
          }

          // Get customer phone (as a string)
          string phoneInput;
          while (true) {
            cout << "Enter customer phone: ";
            cin >> phoneInput;
            if (!phoneInput.empty()) {
              istringstream phoneStream(phoneInput);
              if (phoneStream >> customerPhone && phoneStream.eof()) {
                // Valid integer input
                break;  // Exit the loop
              } else {
                cout << "Invalid phone number. Please enter a valid integer."
                     << endl;
              }
            } else {
              cout << "Phone number cannot be blank. Please enter a valid "
                      "phone number."
                   << endl;
            }
          }

          // Get customer email
          while (true) {
            cout << "Enter customer email: ";
            cin >> customerEmail;
            if (!customerEmail.empty()) {
              break;  // Exit the loop if a non-blank input is provided
            }
            cout << "Email address cannot be blank. Please enter a valid "
                    "email address."
                 << endl;
          }

          // Now you have non-blank inputs in customerName, customerPhone (as an
          // int), and customerEmail Your code can continue here.
          Customer newCustomer(customerName, customerPhone, customerEmail);
          customers.push_back(newCustomer);
          break;
        } else if (customerChoice == 2) {
          // View customers
          cout << "Customers:\n";
          for (Customer &customer : customers) {
            cout << "Name: " << customer.get_name()
                 << ", Phone: " << customer.get_phone()
                 << ", Email: " << customer.get_email() << "\n";
          }
        } else if (customerChoice == 3) {
          break;
        } else {
          cout << "Invalid choice. Please try again.\n";
          break;
        }
      }
    } else if (choice == 4) {
      // Exit
      cout << "Exiting the POS system. Goodbye!\n";
      break;
    } else {
      break;
    }
  }

  return 0;
}

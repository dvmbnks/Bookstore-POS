#include "Inventory.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Book.h"
#include "Digital_Book.h"
#include "Physical_Book.h"
#include "Used_Book.h"

using namespace std;

Inventory::Inventory(){
    
  // Read books from the text file and add them to the inventory
  ifstream inputFile("book2.txt");
  if (!inputFile.is_open())
  {
    cout << "Failed to open the input file." << endl;
  }

  string line;
  int line_index = 1; // Initialize to 1 if you want the index to start at 1

  for (int line_index = 0; line_index < 50; ++line_index)
  {
    if (getline(inputFile, line))
    {
      istringstream iss(line);
      string title, author, genre, platform, condition;
      float rating, price;
      int quantity;
      bool available;

      if (getline(iss, title, ',') && getline(iss, author, ',') &&
          getline(iss, genre, ',') && iss >> rating &&
          iss.ignore() &&                    // Ignore the comma
          iss >> quantity && iss.ignore() && // Ignore the comma
          iss >> price)
      {

        if (quantity <= 0)
        {
          available = false;
        }
        else
        {
          available = true;
        }

        if (line_index <= 20)
        {
          Physical_Book physicalBook(title, author, genre, rating, quantity, price, available);
          add_physical_book(physicalBook);
        }
        if (line_index <= 40 && line_index > 20)
        {
          int number = (rand() % 2) + 1;
          if (number == 1)
          {
            platform = "Zlibrary";
          }
          else
          {
            platform = "Kindle";
          }

          Digital_Book digitalBook(title, author, genre, rating, quantity, price,
                                   platform);
          add_digital_book(digitalBook);
        }

        if (line_index > 40)
        {
          int number = (rand() % 4) + 1;

          // Check the value of 'number' and assign the appropriate condition
          if (number == 1)
          {
            condition = "poor";
          }
          else if (number == 2)
          {
            condition = "okay";
          }
          else if (number == 3)
          {
            condition = "good";
          }
          else
          {
            condition = "Like New";
          }

          Used_Book usedBook(title, author, genre, rating, quantity, price,
                             condition, available);
          add_used_book(usedBook);
        }
      }
    }
  }

  inputFile.close();
}
void Inventory::add_physical_book(const Physical_Book& book) {
    physical_books.push_back(book);
}


void Inventory::add_digital_book(Digital_Book& book) {
    digital_books.push_back(book);
}

void Inventory::add_used_book(Used_Book&  book){
    used_books.push_back(book);
}


void Inventory::remove_physical_book(Physical_Book& book) {
    for (auto it = physical_books.begin(); it != physical_books.end();) {
        if (&(*it) == &book) {
            it = physical_books.erase(it);
        } else {
            ++it;
        }
    }
}

void Inventory::remove_digital_book(Digital_Book& book) {
    for (auto it = digital_books.begin(); it != digital_books.end();) {
        if (&(*it) == &book) {
            it = digital_books.erase(it);
        } else {
            ++it;
        }
    }
}

void Inventory::remove_used_book(Used_Book& book) {
    for (auto it = used_books.begin(); it != used_books.end();) {
        if (&(*it) == &book) {
            it = used_books.erase(it);
        } else {
            ++it;
        }
    }
}

// Search for a book by title and return a pointer to it
Book* Inventory::search_book(string title) {
    // Search in the Physical_Book vector
    for (Physical_Book& book : physical_books) {
        if (book.get_title() == title) {
            // Return a dynamically allocated copy of the book
            return new Physical_Book(book);
        }
    }

    // Search in the Digital_Book vector
    for (Digital_Book& book : digital_books) {
        if (book.get_title() == title) {
            // Return a dynamically allocated copy of the book
            return new Digital_Book(book);
        }
    }

    // Search in the Used_Book vector
    for (Used_Book& book : used_books) {
        if (book.get_title() == title) {
            // Return a dynamically allocated copy of the book
            return new Used_Book(book);
        }
    }

    return nullptr;  // Book not found in any of the vectors
}


// List all books in the inventory
void Inventory::list_books() {
    cout << "List of Books in Inventory:" << endl;

    cout << "Physical Books:" << endl;
    for (Physical_Book& book : physical_books) {
        book.display();
        cout << "\n" << endl;
    }

    cout << "Digital Books:" << endl;
    for (Digital_Book& book : digital_books) {
        book.display();
        cout << "\n" << endl;

    }

    cout << "Used Books:" << endl;
    for (Used_Book& book : used_books) {
        book.display();
        cout << "\n" << endl;

    }
}


// Update book information (e.g., price) by title
void Inventory::update_book(string title) {
    Book* bookToUpdate = search_book(title);

    if (bookToUpdate == nullptr) {
        cout << "Book not found." << endl;
        return;
    }

    string n_title, n_author, n_genre;
    float n_rating;
    int n_quantity;
    float n_price;

    cout << "What would you like to change?\n";
    cout << "1. Title\n";
    cout << "2. Author\n";
    cout << "3. Genre\n";
    cout << "4. Rating\n";
    cout << "5. Quantity\n";
    cout << "6. Price\n";
    cout << "Enter your choice (1-6): ";

    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Enter new title: ";
            cin.ignore(); // Clear the newline character from the previous input
            getline(cin, n_title);
            bookToUpdate->set_title(n_title);
            break;
        case 2:
            cout << "Enter new author: ";
            cin.ignore();
            getline(cin, n_author);
            bookToUpdate->set_author(n_author);
            break;
        case 3:
            cout << "Enter new genre: ";
            cin.ignore();
            getline(cin, n_genre);
            bookToUpdate->set_genre(n_genre);
            break;
        case 4:
            cout << "Enter new rating: ";
            cin >> n_rating;
            bookToUpdate->set_rating(n_rating);
            break;
        case 5:
            cout << "Enter new quantity: ";
            cin >> n_quantity;
            bookToUpdate->set_quantity(n_quantity);
            break;
        case 6:
            cout << "Enter new price: ";
            cin >> n_price;
            bookToUpdate->set_price(n_price);
            break;
        default:
            cout << "Invalid choice.\n";
            return;
    }

    // Now, update the book information in the file (book2.txt)
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
                outputFile << bookToUpdate->get_title() << ","
                           << bookToUpdate->get_author() << ","
                           << bookToUpdate->get_genre() << ","
                           << bookToUpdate->get_rating() << ","
                           << bookToUpdate->get_quantity() << ","
                           << bookToUpdate->get_price() << "\n";
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

    cout << "Book updated and saved to book2.txt.\n";
}



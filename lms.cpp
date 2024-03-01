#include <iostream>
#include <string>
using namespace std;

// Define a struct for a Book
struct Book {
    string title;
    string author;
    int year;
    bool isIssued;
    Book* next;
};

class Library {
public:
    Book* head;

    // Constructor to initialize the library
    Library() {
        head =nullptr;
    }

    // Function to add a new book to the library
    void addBook(const string& title, const string& author, int year) {
        // Create a new book node
        Book* newBook = new Book;
        newBook->title = title;
        newBook->author = author;
        newBook->year = year;
        newBook->isIssued = false;
        newBook->next = nullptr;

        // Check if the library is empty
        if (head == nullptr) {
            head = newBook;
            cout << "Book added successfully!" << endl;
        } else {
            // Traverse the list to find the last node
            Book* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            // Add the new book to the end of the list
            current->next = newBook;
            cout << "Book added successfully!" << endl;
        }
    }

    // Function to search for a book by title
    void searchBook(const string& title) {
        Book* current = head;
        while (current != nullptr) {
            if (current->title == title) {
                cout << "Book found!" << endl;
                cout << "Title: " << current->title << endl;
                cout << "Author: " << current->author << endl;
                cout << "Year: " << current->year << endl;
                cout << "Status: " << (current->isIssued ? "Issued" : "Available") << endl;
                return;
            }
            current = current->next;
        }
        cout << "Book not found!" << endl;
    }

    // Function to issue a book
    void issueBook(const string& title) {
        Book* current = head;
        while (current != nullptr) {
            if (current->title == title) {
                if (!current->isIssued) {
                    current->isIssued = true;
                    cout << "Book issued successfully!" << endl;
                    return;
                } else {
                    cout << "Book is already issued." << endl;
                    return;
                }
            }
            current = current->next;
        }
        cout << "Book not found!" << endl;
    }

    // Function to return a book
    void returnBook(const string& title) {
        Book* current = head;
        while (current != nullptr) {
            if (current->title == title) {
                if (current->isIssued) {
                    current->isIssued = false;
                    cout << "Book returned successfully!" << endl;
                    return;
                } else {
                    cout << "Book is not issued!" << endl;
                    return;
                }
            }
            current = current->next;
        }
        cout << "Book not found!" << endl;
    }

    // Function to display all books
    void listBooks() {
        Book* current = head;
        if (current == nullptr) {
            cout << "No books in the library." << endl;
        } else {
            cout << "List of Books:" << endl;
            while (current != nullptr) {
                cout << "Title: " << current->title << endl;
                cout << "Author: " << current->author << endl;
                cout << "Year: " << current->year << endl;
                cout << "Status: " << (current->isIssued ? "Issued" : "Available") << endl;
                cout << "------------------------" << endl;
                current = current->next;
            }
        }
    }

    // Function to delete a book by title
    void deleteBook(const string& title) {
        Book* current = head;
        Book* prev = nullptr;
        while (current != nullptr) {
            if (current->title == title) {
                if (prev == nullptr) {
                    // Deleting the head node
                    head = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                cout << "Book deleted successfully!" << endl;
                return;
            }
            prev = current;
            current = current->next;
        }
        cout << "Book not found!" << endl;
    }
};

int main() {
    Library library;
    int choice;
    string title, author;
    int year;

    do {
        cout << "**** Library Management System ****" << endl;
        cout << "1. Add New Book" << endl;
        cout << "2. Search for a Book" << endl;
        cout << "3. Issue a Book" << endl;
        cout << "4. Return a Book" << endl;
        cout << "5. List all Books" << endl;
        cout << "6. Delete a Book" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter book title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter book author: ";
                getline(cin, author);
                cout << "Enter book year: ";
                cin >> year;
                library.addBook(title, author, year);
                break;
            case 2:
                cout << "Enter book title to search: ";
                cin.ignore();
                getline(cin, title);
                library.searchBook(title);
                break;
            case 3:
                cout << "Enter book title to issue: ";
                cin.ignore();
                getline(cin, title);
                library.issueBook(title);
                break;
            case 4:
                cout << "Enter book title to return: ";
                cin.ignore();
                getline(cin, title);
                library.returnBook(title);
                break;
            case 5:
                library.listBooks();
                break;
            case 6:
                cout << "Enter book title to delete: ";
                cin.ignore();
                getline(cin, title);
                library.deleteBook(title);
                break;
            case 7:
                cout << "Exiting... Thank you!" << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    } while (choice != 7);

    return 0;
}

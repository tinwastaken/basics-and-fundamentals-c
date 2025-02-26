#include <iostream>
#include <vector>
using namespace std;

class Book {
private:
    string title, author;
    int year;

public:
    // Constructor using an initializer list
    Book(string t, string a, int y) 
        : title(t), author(a), year(y) {}
    
    // Display method
    void showDetails(int index) {
        cout << "\n-------- Book " << index + 1 << " --------" << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Year: " << year << "\n" << endl;
    }
    
    string getTitle() const {
        return title;
    }
    
    string getAuthor() const {
        return author;
    }
    
    int getYear() const {
        return year;
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook() {
        string title, author;
        int year;
        
        cout << "\nEnter Title: ";
        cin.ignore();
        getline(cin, title);
        
        cout << "Enter Author: ";
        getline(cin, author);
        
        cout << "Enter Year: ";
        cin >> year;
        
        books.push_back(Book(title, author, year));
        cout << "\nBook added successfully!\n";
    }
    
    void displayBooks() {
        if (books.empty()) {
            cout << "\nNo books available.\n";
            return;
        }
        cout << "\nBook List:\n";
        for (size_t i = 0; i < books.size(); ++i) {
            books[i].showDetails(i);
        }
    }
    
    void searchBook() {
        string searchTitle;
        cout << "\nEnter a book to search: ";
        cin.ignore();
        getline(cin, searchTitle);
        
        for (size_t i = 0; i < books.size(); ++i) {
            if (books[i].getTitle() == searchTitle) {
                cout << "\nBook found!\n";
                books[i].showDetails(i);
                return;
            }
        }
        cout << "\nBook not found!\n";
    }
};

int main() {
    Library library;
    int choice;
    char repeat;
    
    do {
        cout << "\nMenu\n1 - Add Book\n2 - Display Books\n3 - Search Book\n4 - Exit\nEnter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                library.addBook();
                break;
            case 2:
                library.displayBooks();
                break;
            case 3:
                library.searchBook();
                break;
            case 4:
                cout << "\nExiting program...\n";
                return 0;
            default:
                cout << "\nInvalid choice. Please try again.\n";
        }
        
        cout << "\nDo you want to choose another operation? (y/n): ";
        cin >> repeat;
        
    } while (repeat == 'y' || repeat == 'Y');
    
    cout << "\nDestroyed.\n";
    return 0;
}
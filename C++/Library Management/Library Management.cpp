#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <regex>

using namespace std;

class User {
private:
    string name;
    string id;
    string contactInfo;

public:
    User(string n, string i, string c) : name(n), id(i), contactInfo(c) {}

    string getName() const { return name; }
    string getId() const { return id; }
    string getContactInfo() const { return contactInfo; }
    void setName(const string& nn) { name = nn; }
    void setId(const string& ii) { id = ii; }
    void setContactInfo(const string& ci) { contactInfo = ci; }
    void displayInfo() const {
        cout << "Name: " << name << ", ID: " << id << ", Contact Info: " << contactInfo << endl;
    }
};

class Book {
private:
    string title;
    string isbn;
    string author;
    string publicationYear;
    string genre;
    bool availability;

public:
    Book(string t, string is, string a, string p, string g, bool avail)
        : title(t), isbn(is), author(a), publicationYear(p), genre(g), availability(avail) {}

    string getTitle() const { return title; }
    string getISBN() const { return isbn; }
    string getAuthor() const { return author; }
    string getPublicationYear() const { return publicationYear; }
    string getGenre() const { return genre; }
    bool isAvailable() const { return availability; }
    void setTitle(const string& t) { title = t; }
    void setISBN(const string& is) { isbn = is; }
    void setAuthor(const string& a) { author = a; }
    void setPublicationYear(const string& p) { publicationYear = p; }
    void setGenre(const string& g) { genre = g; }
    void setAvailability(bool avail) { availability = avail; }
    void displayInfo() const {
        cout << "Title: " << title << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Author: " << author << endl;
        cout << "Publication Year: " << publicationYear << endl;
        cout << "Genre: " << genre << endl;
        cout << "Availability: " << (availability ? "Available" : "Not Available") << endl;
    }
};

// Global Variables
int choice;
string name, id, contactInfo;
string bookTitle, isbn, author, year, genre;
bool availability;
string query;
regex date_pattern(R"((\d{4})-(\d{2})-(\d{2}))");

vector<User> userList;
vector<Book> bookList;

// Function prototypes
void findIdThenRemove(string id);
void findIdThenModify(string id);

int main() {
    cout << "LIBRARY MANAGEMENT SYSTEM" << endl;
    cout << "1. add user\n"
         << "2. remove user\n"
         << "3. update user\n"
         << "4. view users\n"
         << "5. add book\n"
         << "6. remove book\n"
         << "7. search book\n"
         << "8. update book details\n"
         << "9. view books\n";

    while (true) {
        cout << "Choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                cout << "Enter name: ";
                getline(cin, name);
                cout << "Id: ";
                getline(cin, id);
                cout << "Contact info: ";
                getline(cin, contactInfo);

                if (contactInfo.length() != 11) {
                    cout << "Invalid contact info, enter 11 digits." << endl;
                } else {
                    userList.emplace_back(name, id, contactInfo);
                    cout << "New user added." << endl;
                }
                break;
            }

            case 2: {
                string toRemove;
                cout << "Enter user id to remove: ";
                cin >> toRemove;
                findIdThenRemove(toRemove);
                break;
            }

            case 3: {
                string find;
                cout << "Enter user id to track: ";
                cin >> find;
                findIdThenModify(find);
                break;
            }

            case 4: {
                for (const auto& users : userList) {
                    users.displayInfo();
                }
                break;
            }

            case 5: {
                cout << "Enter book title: ";
                getline(cin, bookTitle);
                cout << "ISBN: ";
                getline(cin, isbn);
                cout << "Author: ";
                getline(cin, author);
                cout << "Year (yyyy-MM-dd): ";
                getline(cin, year);
                cout << "Genre: ";
                getline(cin, genre);
                cout << "Availability (1 for true, 0 for false): ";
                cin >> availability;

                if (!regex_match(year, date_pattern)) {
                    cout << "Please enter a valid date format (yyyy-MM-dd)." << endl;
                    break;
                }

                bookList.emplace_back(bookTitle, isbn, author, year, genre, availability);
                cout << "New book added." << endl;
                break;
            }

            case 6: {
                cout << "Enter book isbn to remove: ";
                getline(cin, query);
                auto it = bookList.begin();
                bool found = false;
                while (it != bookList.end()) {
                    if (it->getISBN() == query) {
                        it = bookList.erase(it);
                        cout << "Book removed." << endl;
                        found = true;
                    } else {
                        ++it;
                    }
                }
                if (!found) {
                    cout << "Book not found." << endl;
                }
                break;
            }

            case 7: {
                cout << "Enter your query (book title): ";
                getline(cin, query);
                bool found = false;
                for (const auto& b : bookList) {
                    if (b.getTitle() == query) {
                        found = true;
                        cout << "Book found.\nDetails: ";
                        b.displayInfo();
                        break;
                    }
                }
                if (!found) {
                    cout << "Book not found." << endl;
                }
                break;
            }

            case 8: {
                cout << "Enter book ISBN to update details: ";
                getline(cin, query);
                bool found = false;
                for (auto& b : bookList) {
                    if (b.getISBN() == query) {
                        found = true;

                        cout << "Enter new title (leave blank to keep current): ";
                        getline(cin, bookTitle);
                        if (!bookTitle.empty()) {
                            b.setTitle(bookTitle);
                        }

                        cout << "Enter new author (leave blank to keep current): ";
                        getline(cin, author);
                        if (!author.empty()) {
                            b.setAuthor(author);
                        }

                        cout << "Enter new publication year (leave blank to keep current): ";
                        getline(cin, year);
                        if (!year.empty() && regex_match(year, date_pattern)) {
                            b.setPublicationYear(year);
                        } else {
                            cout << "Invalid year format." << endl;
                        }

                        cout << "Enter new genre (leave blank to keep current): ";
                        getline(cin, genre);
                        if (!genre.empty()) {
                            b.setGenre(genre);
                        }

                        cout << "Set availability (1 for true, 0 for false): ";
                        cin >> availability;
                        b.setAvailability(availability);

                        cout << "Book details updated." << endl;
                        break;
                    }
                }
                if (!found) {
                    cout << "Book not found." << endl;
                }
                break;
            }

            case 9: {
                for (const auto& b : bookList) {
                    b.displayInfo();
                }
                break;
            }

            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    }
    return 0;
}

void findIdThenRemove(string id) {
    auto it = userList.begin();
    bool found = false;
    while (it != userList.end()) {
        if (it->getId() == id) {
            it = userList.erase(it);
            cout << "User removed." << endl;
            found = true;
        } else {
            ++it;
        }
    }
    if (!found) {
        cout << "User not found." << endl;
    }
}

void findIdThenModify(string id) {
    bool found = false;
    for (auto& u : userList) {
        if (u.getId() == id) {
            found = true;
            cout << "Updating user info." << endl;
            string newName, newContactInfo;

            cout << "New Name (leave blank to keep current): ";
            getline(cin, newName);
            if (!newName.empty()) {
                u.setName(newName);
            }

            cout << "New Contact Info (leave blank to keep current): ";
            getline(cin, newContactInfo);
            if (!newContactInfo.empty() && newContactInfo.length() == 11) {
                u.setContactInfo(newContactInfo);
            } else if (!newContactInfo.empty()) {
                cout << "Invalid contact info. Must be 11 digits." << endl;
            }

            cout << "User info updated." << endl;
            break;
        }
    }
    if (!found) {
        cout << "User not found." << endl;
    }
}

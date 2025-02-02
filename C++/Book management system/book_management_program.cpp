#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <limits>

using namespace std;

struct Book{
	string title, author;
	int copies, bookId;
	string isAvailable;
	
	Book(string t, string a, int c, int bId, string is) {
        title = t;
        author = a;
        copies = c;
        bookId = bId;
        isAvailable = is;
    }

    // Getter functions
    string getTitle() { return title; }
    string getAuthor() { return author; }
    int getCopies() { return copies; }
    int getBookId() { return bookId; }
    string getAvailabilityStatus() { return isAvailable; }

    // Setter functions
    void setTitle(string t) { title = t; }
    void setAuthor(string a) { author = a; }
    void setCopies(int c) { copies = c; }
    void setBookId(int bId) { bookId = bId; }
    void setAvailabilityStatus(string is) { isAvailable = is; }

    // Function to display book information
    void displayInfo() {
        cout << "Book ID: " << bookId << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Copies: " << copies << endl;
        cout << "Availability Status: " << isAvailable << endl;
    }
    
    void save(ofstream &outfile) const{
    	outfile << title << ", " << author << ", " << copies << ", " << bookId << ", " << isAvailable << endl;
	}
};

vector<Book> book_list;

void addBook(string title, string author, int copies, int id, string status){    
	//check for duplicates first
	for(const Book& book : book_list){
		if(book.bookId == id){
			cout << "Book already exists." << endl;
			return;
		}
	}
	    
	Book new_book(title, author, copies, id, status);
	book_list.push_back(new_book);
	cout << "Book added." << endl;
}

void showRecords(){
	if(book_list.empty()){
		cout << "No books available." << endl;
		return;
	}
	
	int count = 1;
	for(auto &b : book_list){
		cout << count << ". ";
		b.displayInfo();
		cout << endl;
		count++;
	}
}

void checkAvailability(int id){
	bool found = false;
	for(auto it = book_list.begin(); it != book_list.end(); ++it){
		if(it->bookId == id){
			found = true;
			cout << "Book title: " << it->getTitle() << ", Availability Status: " << it->getAvailabilityStatus() << endl;
			break;
		}
	}
	if(!found){
		cout << "No book found with id: " << id << endl;
	}
}

void modifyRecords() {
    int id;
    cout << "Enter the Book ID to modify: ";
    cin >> id;
    
    for (auto& book : book_list) {
        if (book.getBookId() == id) {
            cout << "Book found! Enter new details:\n";
            string newTitle, newAuthor, availability;
            int newCopies;
            
            cout << "Enter new title (current: " << book.getTitle() << "): ";
            cin.ignore();
            getline(cin, newTitle);
            cout << "Enter new author (current: " << book.getAuthor() << "): ";
            getline(cin, newAuthor);
            cout << "Enter new number of copies (current: " << book.getCopies() << "): ";
            cin >> newCopies;
            cout << "Enter availability (current: " << book.getAvailabilityStatus() << "): ";
            getline(cin, availability);
            
            book.setTitle(newTitle);
            book.setAuthor(newAuthor);
            book.setCopies(newCopies);
        	book.setAvailabilityStatus(availability);
			
            cout << "Book details updated successfully." << endl;
            return;
        }
    }
    cout << "Book not found!" << endl;
}

void deleteRecord(int id){
	for(auto it = book_list.begin(); it != book_list.end(); ++it){
		if(id == it->getBookId()){
			book_list.erase(it);
			cout << "Book removed." << endl;
			return;
		}
	}
	cout << "Book with ID '" << id << "' not found." << endl;
}

void saveToFile(){
	ofstream outfile("book_data.txt");
	if(outfile.is_open()){
		for(const auto &book : book_list){
			book.save(outfile);
			cout << "Data saved to book_data.txt." << endl;
			outfile.close();
		}
	}else{
		cerr << "An error occured when writing to the file." << endl;
	}
}

int main(){
	string choices[] = {"Add book", "View all books", "Check availability", "Update book details", "Delete book", "Save to file", "Exit"};
	int size = sizeof(choices) / sizeof(choices[0]);
	for(int i = 0; i < size; i++){
		cout << (i + 1) << ". " << choices[i] << endl;
	}
	
	int choice;
	
	string title, author, availability;
	int copies, id;
	
	//vector for available options for availability: available and unavailable
	vector<string> options = {"Available", "Unavailable"};
	
	while(true){
		cout << "Enter choice: ";
		cin >> choice;
		
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		
		switch(choice){
			case 1: {
				string input;
				cout << "Enter title: ";
				getline(cin, title);
				cout << "Author: ";
				getline(cin, author);
				cout << "Copies: ";
				cin >> copies;
				cout << "Id: ";
				cin >> id;
				cout << "Availability: ";
				cin >> availability;
				
				for(auto &a : options){
					if(availability == a){
						addBook(title, author, copies, id, availability);
					}else{
						cout << "Enter available or unavailable only." << endl;
					}
				}
				break;
			}
				
			case 2:
				showRecords();
				break;
			
			case 3:
				cout << "Enter book id to check if its available: ";
				cin >> id;
				checkAvailability(id);
				break;
				
			case 4:
				modifyRecords();
				break;
				
			case 5:
				cout << "Enter book id to remove: ";
				cin >> id;
				deleteRecord(id);
				break;
				
			case 6:
				saveToFile();
				break;
				
			case 7:
				cout << "Exiting...";
				return 0;
			
			default:
				cout << "Input valid choice.";
				break;
		}
	}
}
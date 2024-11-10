#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <algorithm>
#include <random>

using namespace std;

class Task {
private:
    int id;
    string title;
    string description;
    string dueDate;
    int priority;
    bool completed;

public:
    Task(int id, string title, string description, string dueDate, int priority, string status)
        : id(id), title(title), description(description), dueDate(dueDate), priority(priority) {
            // Set the completed status based on the string input
            completed = (status == "completed" || status == "Completed");
    }

    int getId() const { return id; }
    string getTitle() const { return title; }
    string getDescription() const { return description; }
    string getDueDate() const { return dueDate; }
    int getPriority() const { return priority; }
    bool isCompleted() const { return completed; }
	
    void setTitle(const string& newTitle) { title = newTitle; }
    void setDescription(const string& newDescription) { description = newDescription; }
    void setDueDate(const string& newDueDate) { dueDate = newDueDate; }
    void setPriority(int newPriority) { priority = newPriority; }
    void markCompleted(bool status) { completed = status; }

    void displayTask() const {
        cout << "Task ID: " << id << "\nTitle: " << title << "\nDescription: " << description
             << "\nDue Date: " << dueDate << "\nPriority: " << priority
             << "\nCompleted: " << (completed ? "Yes" : "No") << endl;
    }
};

class Contact {
private:
    int id;
    string name;
    string phoneNumber;
    string email;

public:
    Contact(int id, const string& name, const string& phoneNumber, const string& email)
        : id(id), name(name), phoneNumber(phoneNumber), email(email) {}

    int getId() const { return id; }
    string getName() const { return name; }
    string getPhoneNumber() const { return phoneNumber; }
    string getEmail() const { return email; }

    void setName(const string& newName) { name = newName; }
    void setPhoneNumber(const string& newPhoneNumber) { phoneNumber = newPhoneNumber; }
    void setEmail(const string& newEmail) { email = newEmail; }

    void displayContact() const {
        cout << "Contact ID: " << id << "\nName: " << name << "\nPhone Number: " << phoneNumber
             << "\nEmail: " << email << endl;
    }
};

class Event {
private:
    int id;
    string date;
    string title;
    string description;
    string location;

public:
    Event(int id, const string& date, const string& title, const string& description, const string& location)
        : id(id), date(date), title(title), description(description), location(location) {}

    int getId() const { return id; }
    string getDate() const { return date; }
    string getTitle() const { return title; }
    string getDescription() const { return description; }
    string getLocation() const { return location; }

    void setDate(const string& newDate) { date = newDate; }
    void setTitle(const string& newTitle) { title = newTitle; }
    void setDescription(const string& newDescription) { description = newDescription; }
    void setLocation(const string& newLocation) { location = newLocation; }

    void displayEvent() const {
        cout << "Event ID: " << id << "\nDate: " << date << "\nTitle: " << title
             << "\nDescription: " << description << "\nLocation: " << location << endl;
    }
};

class Note {
private:
    int id;
    string content;
    string creationDate;

public:
    Note(int id, const string& content, const string& creationDate)
        : id(id), content(content), creationDate(creationDate) {}

    int getId() const { return id; }
    string getContent() const { return content; }
    string getCreationDate() const { return creationDate; }

    void setContent(const string& newContent) { content = newContent; }
    void setCreationDate(const string& newCreationDate) { creationDate = newCreationDate; }

    void displayNote() const {
        cout << "Note ID: " << id << "\nContent: " << content << "\nCreation Date: " << creationDate << endl;
    }
};

vector<Task> tasks;
vector<Contact> contacts;
vector<Event> events;
vector<Note> notes;

map<int, Task> taskMap;
map<string, Contact> contactMap;
map<int, Event> eventMap;
map<int, Note> noteMap;

int choice;

//function prototypes
void addTask();
void updateTask();
void editTask();
void deleteTask();

void addContact();
void searchContact();
void updateContact();
void saveContact();
void viewContacts();
void findIDThenEdit(int id);

ofstream outfile("tasksFile.txt");

int main(){
	cout << "PERSONAL ORGANIZER\n";
	cout << "1. Add new task\n2. Edit task\n3. Delete task\n4. Add contact\n5. Update contact\n6. Delete contact\n7. Search contacts\n7. save contacts\n8. View all contacts";
	cout << "\n";
	
	while(true){
		cout << "Choice: ";
		cin >> choice;
		
		switch(choice){
			case 1:
				addTask();
				break;
			case 2:
				editTask();
				break;
			case 3:
				deleteTask();
				break;
			case 4:
				addContact();
				break;
			case 5:
				updateContact();
				break;
			case 6:
				searchContact();
				break;
			case 7:
				saveContact();
				break;
			case 8:
				viewContacts();
				break;
			default:
				cerr << "Invalid choice.";
				break;
		}
	}
	return 0;
}

void addTask() {
    string title, description, dueDate, status;
    int id, priority;

    cout << "Task title: ";
    getline(cin, title);
    
    cout << "Description: ";
    getline(cin, description);

    cout << "Due date: ";
    getline(cin, dueDate);

    cout << "ID: ";
    cin >> id;

    cout << "Priority (1-5): ";
    while (true) {
        cin >> priority;
        if (priority >= 1 && priority <= 5) {
            break;
        } else {
            cout << "Invalid task priority. Enter a value between 1 and 5: ";
        }
    }

    cin.ignore();
    cout << "Status (completed or not): ";
    getline(cin, status);

    Task task(id, title, description, dueDate, priority, status);
    tasks.push_back(task);
    cout << "TASK ADDED.\n";
}

void editTask(){
	int id;
	cout << "Enter the task id to find: ";
	cin >> id;
	findIDThenEdit(id);
}

void deleteTask(){
	int id;
	cout << "Enter task id to delete: ";
	cin >> id;
	
	bool found = false;
	for(Task task : tasks){
		if(id == task.getId()){
			tasks.erase(remove_if(tasks.begin(), tasks.end(), [id](Task& t) { return t.getId() == id; }), tasks.end());
			found = true;
			cout << "Task removed.";
			break;
		}
	}
	cout << "Task not found.";
}

void addContact(){
	string name, phone, email;
    int id;
    string value = "@";
	
	cout << "Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "ID: ";
    cin >> id;
    cout << "Phone number: ";
    cin >> phone;  
    cout << "Email: ";
    cin >> email;
	
	if(email.find(value) != string::npos && phone.length() == 11){
        Contact contact(id, name, phone, email);
        contacts.push_back(contact);
        cout << "New contact added.\n";
    }else{
        cerr << "Enter a valid phone number and email address.\n";
    }
}

void updateContact() {
    int contactId;
    bool found = false;
    string choice;
    string newInput;

    cout << "Enter Contact ID to update: ";
    cin >> contactId;
    cin.ignore();
	
    for (int i = 0; i < contacts.size(); i++) {
        if (contacts[i].getId() == contactId) {
            found = true;

            cout << "What would you like to update? (name, phone, email): ";
            getline(cin, choice);

            if(choice == "name"){
                cout << "Enter new name: ";
                getline(cin, newInput);
                contacts[i].getName() = newInput;
            }
            else if(choice == "phone"){
                cout << "Enter new phone number: ";
                getline(cin, newInput);
                contacts[i].getPhoneNumber() = newInput;
            }
            else if(choice == "email"){
                cout << "Enter new email: ";
                getline(cin, newInput);
                contacts[i].getEmail() = newInput;
            }
            else{
                cout << "Invalid option." << endl;
            }
            cout << "Contact updated successfully." << endl;
            break;
        }
    }
    if(!found){
        cout << "Contact not found." << endl;
    }
}

void searchContact(){
	int id;
	cout << "Enter contact id to find: ";
	cin >> id;
	cin.ignore();
	
	bool found = false;
	for(Contact c : contacts){
		if(id == c.getId()){
			found = true;
			cout << "Task found.\n";
			cout << "Task: " << c.getName() << ", Number: " << c.getPhoneNumber() << ", Email: " << c.getEmail() << endl;
			break;
		}else{
			cout << "Contact not found.";
			return;
		}
	}
}

void saveContact(){
	string contactFile = "C:\\Users\\AY\\Desktop\\contacts.txt";
	ofstream outfile(contactFile, ios::app);
	if(!outfile.is_open()){
		cerr << "Error opening the file." << endl;
		return;
	}
	for(const auto& contact : contacts){
        outfile << contact.getId() << "\n" << contact.getName() << "\n"
                << contact.getPhoneNumber() << "\n" << contact.getEmail() << "\n";
    }

    outfile.close();
    cout << "Contact data has been written to " << contactFile << endl;
}

void viewContacts(){
	cout << "All contacts:";
	for(const auto &contact : contacts){
		contact.displayContact();
	}
}

void findIDThenEdit(int id) {
    bool found = false;
    string choice;
    string newtitle, newdescription, newduedate;
    int newpriority;
    bool newStatus;

    for (int i = 0; i < tasks.size(); i++) {
        if (id == tasks[i].getId()) {
            found = true;
            cout << "What to edit? title, description, id, priority, status, due date: ";
            cin.ignore();

            getline(cin, choice);

            if (choice == "title") {
                cout << "Enter new title: ";
                getline(cin, newtitle);
                tasks[i].setTitle(newtitle);
            }
            else if (choice == "description") {
                cout << "Enter new description: ";
                getline(cin, newdescription);
                tasks[i].setDescription(newdescription);
            }
            else if (choice == "priority") {
                cout << "Enter new priority (number): ";
                cin >> newpriority;
                tasks[i].setPriority(newpriority);
                cin.ignore(); 
            }
            else if (choice == "status") {
                string input;
                cout << "Enter new status (1 for completed, 0 for not completed): ";
                cin >> input;
                newStatus = (input == "1");
                tasks[i].markCompleted(newStatus);
                cin.ignore(); 
            }
            else if (choice == "due date") {
                cout << "Enter new due date: ";
                getline(cin, newduedate);
                tasks[i].setDueDate(newduedate);
            }
            else {
                cout << "Invalid option.\n";
            }

            cout << "Task updated successfully.\n";
            break;
        }
    }

    if (!found) {
        cout << "Task not found.\n";
    }
}


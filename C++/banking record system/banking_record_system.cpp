#include <iostream>
#include <vector>
#include <unordered_map>
#include <iomanip>
#include <fstream>

using namespace std;

struct Data {
    string fname, lname;
    float balance;
    int accNumber;

    Data(string f, string l, float b, int a) : fname(f), lname(l), balance(b), accNumber(a) {}

    bool operator==(const Data& other) const {
        return accNumber == other.accNumber;
    }

    string getFname() const { return fname; }
	string getLname() const { return lname; }
	float getBalance() const { return balance; }
	int getAccNumber() const { return accNumber; }


    void setFname(string f) { fname = f; }
    void setLname(string l) { lname = l; }
    void setBalance(float b) { balance = b; }
    void setAccNumber(int a) { accNumber = a; }

    void displayInfo() const {
        cout << "Account Information:\n";
        cout << "First Name: " << fname << endl;
        cout << "Last Name: " << lname << endl;
        cout << "Account Number: " << accNumber << endl;
        cout << fixed << setprecision(2);
        cout << "Balance: $" << balance << endl;
    }

    void saveToFile(ofstream &outFile) const {
        outFile << accNumber << ", " << fname << ", " << lname << ", " << balance << endl;
    }
};

vector<Data> database; //for overall data management
unordered_map<int, Data> db_map; //for searching data 

void addData(string fname, string lname, float bal, int accNum) {
    for (const Data &d : database) {
        if (db_map.find(accNum) != db_map.end()) {
            cout << "Person with this account number already exists." << endl;
            return;
        }
    }
    Data data(fname, lname, bal, accNum);
    database.push_back(data);
    db_map[accNum] = &database.back();
    cout << "Data added." << endl;
}

void readData() {
    if (database.empty()) {
        cout << "No data stored." << endl;
        return;
    }
    for (const Data &d : database) {
        d.displayInfo();
        cout << endl;
    }
}

void searchData(int accNum) {
    bool found = false;
    auto it = db_map.find(accNum);
    if(it != db_map.end()){
    	found = true;
    	Data &s = it->second;
    	
    	cout << "First Name: " << s.getFname() << endl;
        cout << "Last Name: " << s.getLname() << endl;
        cout << "Balance: " << s.getBalance() << endl;
	}
	if(!found){
		cout << "Account not found." << endl;
	}
}

void deleteData(int accNum) {
	auto mapIterator = db_map.find(accNum);
	if(mapIterator != db_map.end()){
		db_map.erase(mapIterator);
	}else{
		cout << "Account not found." << endl;
		return;
	}
	
	for(auto it = database.begin(); it != database.end(); it++){
		if(accNum == it->accNumber){
			database.erase(it);
			cout << "Account deleted." << endl;
		}
	}
}

void saveToFile() {
    ofstream file("data.txt");
    if (file.is_open()) {
        for (const auto &db : database) {
            db.saveToFile(file);
        }
        cout << "Data has been written to data.txt successfully." << endl;
        file.close();
    } else {
        cerr << "There's an error saving the file." << endl;
    }
}

int main() {
    vector<string> choices = {"Add Data", "Read Data", "Search Data", "Delete Data", "Save to file", "Exit"};
    
    while (true) {
        cout << "\nOptions:\n";
        for (size_t i = 0; i < choices.size(); i++) {
            cout << (i + 1) << ". " << choices[i] << endl;
        }

        int choice;
        string fname, lname;
        float balance;
        int accNum;

        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cin.ignore();
                cout << "First name: ";
                getline(cin, fname);
                cout << "Last name: ";
                getline(cin, lname);
                cout << "Balance: ";
                cin >> balance;
                cout << "Account number: ";
                cin >> accNum;
                addData(fname, lname, balance, accNum);
                break;

            case 2:
                readData();
                break;

            case 3:
                cout << "Enter user's account number: ";
                cin >> accNum;
                searchData(accNum);
                break;

            case 4:
                cout << "Enter user's account number: ";
                cin >> accNum;
                deleteData(accNum);
                break;

            case 5:
                saveToFile();
                break;

            case 6:
                cout << "Exiting..." << endl;
                return 0;

            default:
                cout << "Enter a valid choice." << endl;
                break;
        }
    }
}

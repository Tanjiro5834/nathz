#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <fstream>
#include <iomanip>

using namespace std;

struct Bus{
	int busNo;
	string driver;
    string from;
    string to;
    string arrivalTime;
    string departureTime;
    
    Bus(int b, string d, string f, string t, string a, string dp)
        : busNo{b}, driver{d}, from{f}, to{t}, arrivalTime{a}, departureTime{dp} {}

    // Getters
    int getBusNumber() { return busNo; }
    string getDriver() { return driver; }
    string getFrom() { return from; }
    string getTo() { return to; }
    string getArrivalTime() { return arrivalTime; }
    string getDepartureTime() { return departureTime; }

    // Setters
    void setDriver(string d) { driver = d; }
    void setFrom(string f) { from = f; }
    void setTo(string t) { to = t; }
    void setArrivalTime(string a) { arrivalTime = a; }
    void setDepartureTime(string dp) { departureTime = dp; }

    // Display function
    void displayInfo() {
        cout << "Driver: " << driver << "\n"
        	 << "Bus Number: " << busNo << "\n"
             << "From: " << from << "\n"
             << "To: " << to << "\n"
             << "Arrival Time: " << arrivalTime << "\n"
             << "Departure Time: " << departureTime << "\n";
    }
};

vector<Bus> bus;
map<int, string> seatReservations;

void installBusInformation(string driver, string from, string to, string arrival, string departure){
	bool exist = false;
	for(Bus b : bus){
        if(b.getDriver() == driver){  
            exist = true;
            cout << "This bus information is already installed." << endl;
            return; 
        }
    }

	if(!exist){
        Bus new_bus(bus.size() + 1, driver, from, to, arrival, departure);
		bus.push_back(new_bus);
		cout << "Bus information installed." << endl;
	}else{
        cout << "Failed to install bus information." << endl;
    }
}

void reservation(int seatNo, string passengerName){
	if(seatReservations.find(seatNo) != seatReservations.end() && !seatReservations[seatNo].empty()){
		cout << "Seat " << seatNo << " is already reserved by " << seatReservations[seatNo] << ".\n";
	}else{
		seatReservations[seatNo] = passengerName;
        cout << "Seat " << seatNo << " reserved for " << passengerName << "." << endl;
    }
}

void show(const vector<Bus>& buses){
	cout << string(80, '*') << endl;
	
	for (const auto& bus : buses) {
        cout << "* Bus No: " << setw(3) << bus.busNo
                  << "   Driver: " << setw(10) << bus.driver
                  << "   Arrival: " << setw(8) << bus.arrivalTime
                  << "   Departure: " << setw(8) << bus.departureTime << "  *"
                  << std::endl;
        cout << "* From: " << setw(15) << bus.from
                  << "   To: " << setw(15) << bus.to << "                          *"
                  << endl;
        cout << string(80, '*') << endl; 
    }
    
    cout << endl;
    
    const int row = 4, col = 4;
	int n = row * col;
	
	int tbl_nums[row][col];
	int num = 1;
    for(int cols = 0; cols < col; cols++){
    	for(int rows = 0; rows < row; rows++){
    		tbl_nums[rows][cols] = num++;
		}
	}
	
	//fill the numbers with the values from reservation function
    int emptySeats = 0;
    int seatNum;
    map<int, string> reservedSeats;
    
	for(int cols = 0; cols < col; cols++){
    	for(int rows = 0; rows < row; rows++){
    		seatNum = tbl_nums[rows][cols];

            cout << setw(5) << seatNum << ". ";

    		if (seatReservations.find(seatNum) != seatReservations.end() && !seatReservations[seatNum].empty()) {
                cout << setw(10) << seatReservations[seatNum] << "\t";  // Print passenger name if reserved
                reservedSeats[seatNum] = seatReservations[seatNum];
            } else {
                cout << setw(10) << "EMPTY" << "\t";
                emptySeats++;
            }
		}
		cout << endl; 
	}

    for(const Bus& b : bus){
        cout << "There are " << emptySeats << "empty seats in Bus No: " << b.busNo << endl;
    }
    
    cout << endl;

    for (const auto& reserved : reservedSeats) {
        cout << "The seat no " << reserved.first << " is reserved for " << reserved.second << "." << endl;
    }
}

void busesAvailable(){
	if(bus.empty()){
		cout << "No buses available." << endl;
		return;
	}
	
	for(size_t i = 0; i < bus.size(); i++){
		bus[i].displayInfo();
	}
}

int main(){
	vector<string> choices = {"INSTALL", "RESERVATION", "SHOW", "BUSES AVAILABLE", "EXIT"};
    for(int i = 0; i < choices.size(); i++){
        cout << (i + 1) << ". " << choices[i] << endl;
    }

    int choice;

    string driver, from, to, arrival, departure, passengerName; //include passenger name 
    int prefferedSeat;

    while(true){
        cout << "Choice: ";
        cin >> choice;
        cin.ignore();

        switch(choice){
            case 1:
                cout << "Enter driver name: ";
                getline(cin, driver);
                cout << "From: ";
                getline(cin, from);
                cout << "To: ";
                getline(cin, to);
                cout << "Arrival Time: ";
                getline(cin, arrival);
                cout << "Departure Time: ";
                getline(cin, departure);

                if(arrival.find(':') != string::npos && departure.find(':') != string::npos){
                    installBusInformation(driver, from, to, arrival, departure);
                }else{
                    cout << "Enter a valid time for arrival and departure." << endl;
                }
                break;

            case 2:
                cout << "Enter preffered seat number: ";
                cin >> prefferedSeat;
                cin.ignore();
                cout << "Enter passenger name: ";
                getline(cin, passengerName);
                reservation(prefferedSeat, passengerName);
                break;

            case 3:
                show(bus);
                break;
            
            case 4:
                busesAvailable();
                break;

            case 5:
                return 0;
            
            default:
                cerr << "Enter valid choice." << endl;
                break;
        }
    }
}
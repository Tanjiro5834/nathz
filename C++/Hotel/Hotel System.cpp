#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <ctime>
#include <stdlib>
#include <algorithm>

#define MAX_GUEST 20

using namespace std;

void bookRoom();
void cancelReservation();
void checkRooms();

int choice;
vector<Guest> guests;
map<Guest, int> roomMap;
map<Type, vector<int>> roomCategory;

enum Type{
	VIP,
	GROUP,
	SOLO,
	DUO
};

int main() {
	cout << "Hotel Management System";
	string options[] = {"Book room", "Checkout", "Check available rooms", "Give feedback", "View bill", "Exit"};
	while(true){
	    int c = 0;
	    for(string o : options){
	        cout << (c + 1) << ". " << o;
	        c++;
	    }
	    cout << "Your choice: ";
	    cin >> choice;
	    
	    switch(choice){
	        case 1:
	           bookRoom();
	           break;
	        case 2:
	           cancelReservation();
	           break;
	        case 3:
	            checkRooms();
	            break;
	        case 4:
	        	giveFeedback();
	        	break;
	        case 5:
	        	viewBill();
	        	break;
	        case 6:
	        	cout << "Exiting...";
	        	return;
	        default:
	            cout << "Invalid choice.";
	            break;
	    }
	}
}

void initializeRooms(){
	roomCategory[VIP] = {1, 4, 5, 7, 9, 18};
	roomCategory[DUO] = {3, 2, 6, 8, 11};
	roomCategory[SOLO] = {10, 12, 13, 14, 15};
	roomCategory[GROUP] = {16, 17, 20, 19};
	
	for(const auto& pair : roomCategory){
		cout << "Room: " << pair.first << "Category: ";
		for(int value : pair.second){
			cout << value << " ";
		}
		cout << endl;
	}
}

int randomValues(){
	return rand() % 9000 + 1000;
}

void bookRoom(){
    int selectedRoom;
    string name;
    
    initializeRooms();
    
    cout << "Select room: ";
    cin >> selectedRoom;
    cin.ignore();
    
    cout << "Your name: ";
    getline(cin, name);
    
    bool roomFound = false;
    RoomType selectedCategory;
    for(auto &val : roomCategory){
    	auto &rooms = val.second;
    	auto it = find(rooms.begin(), rooms.end(), selectedRoom);
    	if(it != rooms.end()){
    		selectedCategory = val.first;
    		room.erase(it);
    		roomFound = true;
    		break;
		}
	}
	
	if(roomFound){
		int guestID = randomValues();
		Guest guest(name, selectedRoom, guestID);
        roomMap.insert(make_pair(guest, selectedRoom));
        
        cout << "Room " << selectedRoom << " in category " << selectedCategory
             << " booked successfully for " << name << ".\n";
	}else{
		cout << "Selected room not available.";
	}
}

void checkout(){
	char choice;
	cout << "You sure you want to checkout? y/n: ";
	cin >> choice;
	
	if(choice == 'y'){
		
	}
}

void viewBill(){
	
}

void giveFeedback(){
	
}

void viewBill(){
	
}

class Admin{	
	private:
		const int password = 123;
		const string username = "admin";
		string user;
		int pw;
		int attempt = 0;
	public:
	Guest guest;
	
	void login(){
		do{
			cout << "USERNAME: ";
			getline(cin, user);
			cout << "PASSWORD: ";
			cin >> pw;
			
			bool loggedIn = false;
			if(pw == password && user == username){
				loggedIn = true;
				cout << "\n\n";
				mainWindow();
			}else{
				cout << "INCORRECT USERNAME AND PASSWORD TRY AGAIN.";
			}
		}while(attempt != 3);
	}
	
	void mainWindow(){
		while(true){
			int choice;
			cout << "1. View guests\n2. Manage rooms\n3. Guest bills\n4. Exit";
			cout << "Choice: ";
			cin >> choice;
			
			switch(choice){
				case 1:
					viewGuests();
					break;
				case 2:
					manageRooms();
					break;
				case 3:
					guestBills();
					break;
				case 4:
					cout << "EXITING...";
					break;
				case 5:
					cout << "Invalid choice. Try again.";
					break;
			}
		}
	}
	
	void viewGuests(){
		for(Guest guest : guests){
			guest.display();
		}
	}
};

class Guest{
    private:
    string name;
    int roomId;
    string roomtype;
    public:
        Guest(string n, int i, string r){
            name = n;
            roomId = i;
            roomtype = r;
        }
        
        string getName() {return name;}
        int getRoomId() {return roomId;}
        string getRoomType() {return roomtype;}
        
        void setName(string newname){
            name = newname;
        }
        
        void setRoomId(int newroom){
            roomId = newroom;
        }
        
        void setRoomType(string newtype){
            roomtype = newtype;
        }
        void display(){
            cout << "Name: " << name <<  ", Room: " << roomId;
        }
}
#include <iostream>
#include <iomanip>

using namespace std;

bool isSenior(char i);
void menu();
bool isSenior(char i) {
    return (i == 'y' || i == 'Y');
}

void menu() {
    while(true){
    	float cost, amount, change;
	    char input;
	
	    cout << "Cost: ";
	    cin >> cost;
	    cout << "Amount: ";
	    cin >> amount;
	
	    cout << "Are you a senior citizen? enter y/n: ";
	    cin >> input;
	
	    bool seniorStatus = isSenior(input);
	    if (amount >= cost) {
	        change = amount - cost;
	        if (seniorStatus) change *= 0.80;
	    } else {
	        cout << "Insufficient amount. No change will be given." << endl;
	        change = 0;
	    }
	    
	    cout << fixed << setprecision(2);
	    cout << "Change: " << change << endl;
	}
}

int main(int argc, char **argv) {
    menu();
}
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

class Item {
public:
    int quantity;
    string name;
    double price;
    int id;

    Item(string n, int q, double p, int i) {
        name = n;
        quantity = q;
        price = p;
        id = i;
    }

    Item() {
        quantity = 0;
        name = "";
        price = 0.0;
        id = -1;
    }

    int getQuantity() const {
        return quantity;
    }
    string getItemName() const {
        return name;
    }
    double getPrice() const {
        return price;
    }

    void setQuantity(int newquantity) {
        quantity = newquantity;
    }
    void setPrice(double newprice) {
        price = newprice;
    }

    string displayInfo() const {
        ostringstream oss;
	    oss << "Item Name: " << name
	        << ", Quantity: " << quantity
	        << ", Price: " << std::fixed << setprecision(2) << price // 2 decimal places
	        << ", ID: " << id;
	    return oss.str();
    }
};

vector<Item> item_list;
int id_counter = 1; 

void addItem(string name, int quantity, double price, int id) {
    Item item(name, quantity, price, id);
    item_list.push_back(item);
}

void deleteItem(int id) {
    bool found = false;
    for (auto it = item_list.begin(); it != item_list.end(); ++it) {
        if (id == it->id) {
            found = true;
            item_list.erase(it);
            cout << "Item removed.\n";
            break;
        }
    }
    if (!found) cout << "Item not found.\n";
}

void viewAllItems() {
    if (item_list.empty()) {
        cout << "There are no items.\n";
        return;
    }
    for (const auto& items : item_list) {
        cout << items.displayInfo() << endl;
    }
}

void updateItemData() {
    if (item_list.empty()) {
        cout << "There are no items to update.\n";
        return;
    }

    int id;
    cout << "Enter the ID of the item to update: ";
    cin >> id;

    bool found = false;
    for (auto& item : item_list) {
        if (item.id == id) {
            found = true;
            cout << "Item found: " << item.displayInfo() << endl;

            int choice;
            cout << "What would you like to update?\n";
            cout << "1. Name\n2. Quantity\n3. Price\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1: {
                    string newName;
                    cout << "Enter the new name: ";
                    cin.ignore();
                    getline(cin, newName);
                    item.name = newName;
                    cout << "Name updated successfully.\n";
                    break;
                }
                case 2: {
                    int newQuantity;
                    cout << "Enter the new quantity: ";
                    cin >> newQuantity;
                    item.quantity = newQuantity;
                    cout << "Quantity updated successfully.\n";
                    break;
                }
                case 3: {
                    double newPrice;
                    cout << "Enter the new price: ";
                    cin >> newPrice;
                    item.price = newPrice;
                    cout << "Price updated successfully.\n";
                    break;
                }
                default:
                    cout << "Invalid choice.\n";
                    break;
            }
            break;
        }
    }

    if (!found) {
        cout << "Item with ID " << id << " not found.\n";
    }
}

void main_menu() {
    int choice;
    string item;
    int quantity;
    double price;
    int id;

    while (true) {
        cout << "1. Add item\n2. Delete item\n3. View all item(s)\n4. Update item data\n5. Save to file\n6. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter product name: ";
                cin.ignore();
                getline(cin, item);
                cout << "Quantity: ";
                cin >> quantity;
                cout << "Price: ";
                cin >> price;

                // Check for duplicate item
                bool isDuplicate = false;
                for (const Item& items : item_list) {
                    if (item == items.getItemName()) {
                        cout << "This item already exists.\n";
                        isDuplicate = true;
                        break;
                    }
                }
                if (!isDuplicate) {
                	cout << endl;
                    addItem(item, quantity, price, id_counter++);
                    cout << "Item added." << endl;
                }
                break;
            }
            case 2: {
                cout << "Enter item id: ";
                cin >> id;
                deleteItem(id);
                cout << endl;
                break;
            }
            case 3: {
            	cout << "--------------------------------------------" << endl;
                viewAllItems();
                cout << "--------------------------------------------" << endl;
                break;
            }
            case 4: {
                updateItemData();
                break;
            }
            case 5: {
                ofstream outfile("items.txt");
                if (outfile.is_open()) {
                    for (const auto& items : item_list) {
                        outfile << items.displayInfo() << endl; // Each item on a new line
                    }
                    outfile.close();
                    cout << "Items data written to file successfully." << endl;
                } else {
                    cerr << "Unable to open file for writing." << endl;
                }
                cout << endl;
                break;
            }
            case 6: {
                cout << "Exiting the program...\n";
                return;
            }
            default: {
                cout << "Invalid choice." << endl;
                break;
            }
        }
    }
}

int main() {
    main_menu();
    return 0;
}

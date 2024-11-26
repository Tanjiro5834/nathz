#include <bits/stdc++.h>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Task {
    string name;
    int id;
    string description;

    Task(string newName, int newId, string newDescription) 
        : name(newName), id(newId), description(newDescription) {}

    string getName() const { return name; }
    int getId() const { return id; }
    string getDescription() const { return description; }

    void setName(string newName) { name = newName; }
    void setDescription(string newDescription) { description = newDescription; }

    void displayInfo() const {
        cout << "Name: " << name 
             << ", ID: " << id 
             << ", Description: " << description << endl;
    }
};


vector<Task> tasks;

int generateId(int low, int high) {
    return low + rand() % (high - low + 1);
}

void addTask() {
    cin.ignore(); 
    string title, description;

    cout << "Enter task title: ";
    getline(cin, title);

    cout << "Enter task description: ";
    getline(cin, description);

    if (!title.empty() && !description.empty()) {
        int id = generateId(1, 100); 
        tasks.emplace_back(title, id, description);
        cout << "Task added successfully with ID: " << id << endl;
    } else {
        cout << "Error: Title and description cannot be empty!" << endl;
    }
}


void deleteTask() {
    int id;
    cout << "Enter task ID to delete: ";
    cin >> id;

    auto it = find_if(tasks.begin(), tasks.end(), [id](const Task& task) {
        return task.getId() == id;
    });

    if (it != tasks.end()) {
        tasks.erase(it);
        cout << "Task with ID " << id << " deleted successfully." << endl;
    } else {
        cout << "Error: Task with ID " << id << " not found." << endl;
    }
}


void editTask() {
    int id;
    cout << "Enter task ID to edit: ";
    cin >> id;

    auto it = find_if(tasks.begin(), tasks.end(), [id](const Task& task) {
        return task.getId() == id;
    });

    if (it != tasks.end()) {
        cin.ignore(); 
        string newName, newDescription;

        cout << "Enter new name (press Enter to keep current: " << it->getName() << "): ";
        getline(cin, newName);

        cout << "Enter new description (press Enter to keep current: " << it->getDescription() << "): ";
        getline(cin, newDescription);

        if (!newName.empty()) it->setName(newName);
        if (!newDescription.empty()) it->setDescription(newDescription);

        cout << "Task updated successfully." << endl;
    } else {
        cout << "Error: Task with ID " << id << " not found." << endl;
    }
}


void viewTask() {
    if (tasks.empty()) {
        cout << "No tasks available." << endl;
        return;
    }

    cout << "Tasks List:\n";
    for (const auto& task : tasks) {
        task.displayInfo();
    }
}


void sortTask() {
    sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
        return a.getName() < b.getName();
    });
    cout << "Tasks sorted by name successfully." << endl;
}


int main() {
    srand(time(0)); 

    vector<string> options = {
        "Add task", 
        "Delete task", 
        "Edit task", 
        "View tasks", 
        "Sort tasks", 
        "Exit"
    };

    while (true) {
        cout << "\nTask Manager Menu:\n";
        for (size_t i = 0; i < options.size(); ++i) {
            cout << i + 1 << ". " << options[i] << endl;
        }

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addTask(); break;
            case 2: deleteTask(); break;
            case 3: editTask(); break;
            case 4: viewTask(); break;
            case 5: sortTask(); break;
            case 6: cout << "Exiting program. Goodbye!" << endl; return 0;
            default: cout << "Invalid option. Please try again." << endl;
        }
    }

    return 0;
}

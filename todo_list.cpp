#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to display the menu
void displayMenu() {
    cout << "\nTo-Do List Manager\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Delete Task\n";
    cout << "4. Exit\n";
    cout << "Enter your choice (1-4): ";
}

// Function to add a task
void addTask(vector<string>& tasks) {
    string task;
    cout << "Enter task description: ";
    cin.ignore(); // Clear input buffer
    getline(cin, task); // Allow spaces in task description
    if (!task.empty()) {
        tasks.push_back(task);
        cout << "Task added successfully!\n";
    } else {
        cout << "Error: Task description cannot be empty.\n";
    }
}

// Function to view all tasks
void viewTasks(const vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks in the list.\n";
        return;
    }
    cout << "\nYour To-Do List:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i] << endl;
    }
}

// Function to delete a task
void deleteTask(vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to delete.\n";
        return;
    }
    viewTasks(tasks);
    int index;
    cout << "Enter task number to delete: ";
    cin >> index;
    if (index > 0 && index <= static_cast<int>(tasks.size())) {
        tasks.erase(tasks.begin() + (index - 1));
        cout << "Task deleted successfully!\n";
    } else {
        cout << "Error: Invalid task number.\n";
    }
}

int main() {
    vector<string> tasks; // Store tasks dynamically
    int choice;

    while (true) {
        displayMenu();
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 4) {
            cout << "Error: Please enter a number between 1 and 4.\n";
            cin.clear();
            cin.ignore(10000, '\n'); // Clear invalid input
            continue;
        }

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                deleteTask(tasks);
                break;
            case 4:
                cout << "Exiting To-Do List Manager. Goodbye!\n";
                return 0;
        }
    }

    return 0;
}
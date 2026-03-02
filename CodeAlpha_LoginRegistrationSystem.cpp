#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

// Function to check if username already exists
bool isDuplicateUsername(const string& username) {
    ifstream file("users.txt");
    string line, storedUsername;
    while (getline(file, line)) {
        stringstream ss(line);
        ss >> storedUsername;
        if (storedUsername == username) {
            file.close();
            return true; // Duplicate found
        }
    }
    file.close();
    return false;
}

// Registration function
void registerUser() {
    string username, password;

    cout << "Enter new username: ";
    cin >> username;
    cout << "Enter new password: ";
    cin >> password;

    // Input validation
    if (username.empty() || password.empty()) {
        cout << "Error: Username or password cannot be empty.\n";
        return;
    }

    // Duplicate check
    if (isDuplicateUsername(username)) {
        cout << "Error: Username already exists. Choose a different username.\n";
        return;
    }

    // Store credentials in users.txt
    ofstream file("users.txt", ios::app);
    file << username << " " << password << endl;
    file.close();

    cout << "Registration successful!\n";
}

// Login function
bool loginUser() {
    string username, password, storedUsername, storedPassword;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");
    while (file >> storedUsername >> storedPassword) {
        if (storedUsername == username && storedPassword == password) {
            cout << "Login successful!\n";
            file.close();
            return true;
        }
    }
    file.close();
    cout << "Login failed! Username or password incorrect.\n";
    return false;
}

// Main menu
int main() {
    int choice;
    cout << "===== Welcome to User System =====\n";
    cout << "1. Register\n2. Login\nEnter your choice: ";
    cin >> choice;

    if (choice == 1) {
        registerUser(); // Call registration function
    } else if (choice == 2) {
        loginUser(); // Call login function
    } else {
        cout << "Invalid choice!\n"; // Invalid menu option
    }

    return 0;
}
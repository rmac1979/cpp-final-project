#include "PasswordProtect.h"
#include <fstream>
#include <cstdlib>
#include <ctime>

// Function to generate a password based on user input
void generatePassword(int length, bool useSpecialChars, bool useNumbers, int complexityLevel) {
    std::string password = getPassword(complexityLevel, useSpecialChars, useNumbers, length);
    std::cout << "Generated Password: " << password << std::endl;

    // Store the credentials (username and location will be taken from user input later)
    std::string username, location;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter location (e.g., email, website): ";
    std::cin >> location;

    storeCredentials(username, password, location);
}

// Store credentials into a file
void storeCredentials(const std::string &username, const std::string &password, const std::string &location) {
    std::ofstream file("credentials.txt", std::ios::app);  // Open file in append mode

    if (file.is_open()) {
        file << "Username: " << username << "\n"
             << "Password: " << password << "\n"
             << "Location: " << location << "\n"
             << "------------------------\n";
        file.close();
        std::cout << "Credentials stored successfully!" << std::endl;
    } else {
        std::cerr << "Error opening file!" << std::endl;
    }
}

// View the stored credentials
void viewStoredCredentials() {
    std::ifstream file("credentials.txt");

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    } else {
        std::cerr << "No stored credentials found!" << std::endl;
    }
}

// Helper function to generate password
std::string getPassword(int complexityLevel, bool useSpecialChars, bool useNumbers, int length) {
    std::string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string specialChars = "!@#$%^&*()_+-=[]{}|;:,.<>?";
    std::string numbers = "0123456789";

    // Adjust character pool based on user preferences
    if (useSpecialChars) characters += specialChars;
    if (useNumbers) characters += numbers;

    std::string password = "";
    srand(time(0));  // Seed random number generator

    for (int i = 0; i < length; ++i) {
        int index = rand() % characters.size();
        password += characters[index];
    }

    return password;
}

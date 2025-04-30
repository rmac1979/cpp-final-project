#include "PasswordProtect.h"

int main() {
    int option;
    int length, complexityLevel;
    bool useSpecialChars, useNumbers;

    while (true) {  // Infinite loop for the main menu
        std::cout << "\nPassword Protection Program\n";
        std::cout << "1. Generate a new password\n";
        std::cout << "2. View stored credentials\n";
        std::cout << "3. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> option;

        switch (option) {
            case 1:
                std::cout << "Enter password length: ";
                std::cin >> length;
                std::cout << "Complexity level (1 - simple, 2 - medium, 3 - complex): ";
                std::cin >> complexityLevel;
                std::cout << "Include special characters? (1 for yes, 0 for no): ";
                std::cin >> useSpecialChars;
                std::cout << "Include numbers? (1 for yes, 0 for no): ";
                std::cin >> useNumbers;

                // Generate password and store credentials
                generatePassword(length, useSpecialChars, useNumbers, complexityLevel);

                break;

            case 2:
                std::cout << "\nStored Credentials:\n";
                viewStoredCredentials();
                break;

            case 3:
                std::cout << "Exiting program.\n";
                return 0;  // Exit the program

            default:
                std::cout << "Invalid option, try again.\n";
                break;
        }
    }

    return 0;
}

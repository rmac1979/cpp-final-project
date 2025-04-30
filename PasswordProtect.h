#ifndef PASSWORDPROTECT_H
#define PASSWORDPROTECT_H

#include <iostream>
#include <string>

// Function declarations
void generatePassword(int length, bool useSpecialChars, bool useNumbers, int complexityLevel);
void storeCredentials(const std::string &username, const std::string &password, const std::string &location);
void viewStoredCredentials();
std::string getPassword(int complexityLevel, bool useSpecialChars, bool useNumbers, int length);

#endif

#pragma once            // To ensure that this file is included only once
#include <iostream>
#include <fstream>      // For file handling operations
#include <iomanip>      // For formatted output
#include <cctype>       // For character operations
#include <string>       // For string operations
#include <unordered_map>// For unordered map
#include <ctime>        // For date-based account numbers
#include <vector>       // For storing multiple user objects
#include "json.hpp"     // JSON library for serialization

using json = nlohmann::json;    // Alias for easier usage

// Enum for account types
typedef enum Type_ { SAVINGS = 0, CURRENT = 1 } Type;
extern const std::unordered_map<Type, std::string> accountTypeMap;  // Maps Type to string for scalability

class User {
private:
    std::string account_number;
    std::string user_name;
    double account_balance;
    Type account_type;

    static int counter;
    static std::string getCurrentDate();    // Static function to get formatted date //yyyymmdd

public:
    User();                     // Constructor
    ~User();                    // Destructor

    void createAccount();        // Creates a new account
    void displayAccount() const; // Displays account details
    void modifyAccount();        // Modifies account (name & type)
    void deleteAccount();        // Deletes an account
    void deposit(double amount); // Deposits money
    bool withdraw(double amount);// Withdraws money

    // Getter for account_number
    std::string getAccountNumber() const; 

    // JSON Serialization
    json toJson() const;
    static void saveToJson();
    static std::vector<User> loadFromJson();

    // CSV Export
    static void exportToCSV(const std::vector<User>& users);

    // Get-Set Methods for Testing
    void setUserName(const std::string& name);
    void setAccountType(Type type);
    void setBalance(double balance);
    double getBalance() const;
};


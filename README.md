# Bank Management System
![Made with C++](https://img.shields.io/badge/Made%20with-C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![MIT License](https://img.shields.io/badge/License-MIT-yellow.svg?style=for-the-badge)
![Platform](https://img.shields.io/badge/Platform-Linux%20%7C%20Windows-lightgrey?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Active-brightgreen?style=for-the-badge)

A lightweight and scalable **C++ console application** featuring core banking functionalities with structured data storage in **JSON** and **CSV**.


## 📌 **Features**  
✅ **Create Accounts** (Savings & Current)  
✅ **View Account Details**  
✅ **Modify Account (Name & Type)**  
✅ **Deposit & Withdraw Money**  
✅ **Delete Account**  
✅ **Save & Load Data in JSON**  
✅ **Export Data to CSV**  


## 📜 **Table of Contents**  
1. [Installation & Setup](#installation--setup)  
2. [Usage Guide](#usage-guide)  
3. [File & Directory Structure](#file--directory-structure)  
4. [Code Explanation](#code-explanation)  
5. [Data Storage Formats](#data-storage-formats)  
6. [Error Handling](#error-handling)  
7. [Contribution Guidelines](#contribution-guidelines)  
8. [License](#license)  
9. [Credits & Authors](#credits--authors)  


## ⚙️ **Installation & Setup**  

### **🔹 Prerequisites**  
- **C++ Compiler** (GCC, Clang, MSVC, etc.)  
- **C++17 or later**  
- **JSON Library** ([nlohmann/json](https://github.com/nlohmann/json))  

### **🔹 Steps to Run**  
1️⃣ **Clone the Repository:**  
```sh
git clone https://github.com/kreeeesh17/bank-managment-system.git
cd bank-management-system
```

2️⃣ **Compile the Code:**  
```sh
g++ -o bank main.cpp src/user.cpp -std=c++17 -Iinclude
```
OR 

```sh
make
```

3️⃣ **Run the Program:**  
```sh
./bank
```
OR

```sh
make run
```
4️⃣ **Clear the Database and Executables after use:** 
```sh
make clean
```

## 📖 **Usage Guide**  

### **1️⃣ Create an Account**  
- The system prompts for **Name** and **Account Type** (Savings/Current).  
- Generates a **unique account number** based on the date and a counter.  

### **2️⃣ View Account Details**  
```markdown
1. Enter your account number.
2. See Number, Name, Balance, and Type.
```

### **3️⃣ Deposit Money**  
```markdown
1. Enter account number.
2. Enter deposit amount.
3. Balance updates automatically.
```

### **4️⃣ Withdraw Money**  
```markdown
1. Enter account number.
2. Enter withdrawal amount.
3. If sufficient balance → Success.
4. If not → Error message.
```

### **5️⃣ Modify Account**  
```markdown
1. Enter account number.
2. Change Name & Account Type.
3. Data is saved instantly.
```

### **6️⃣ Delete Account**  
```markdown
1. Enter account number.
2. Confirm deletion.
3. Account is removed from JSON file.
```

### **7️⃣ Export Accounts to CSV**  
```markdown
1. Select CSV export option.
2. Data saved in `data/accounts.csv`.
```


## 📁 **File & Directory Structure**  
```markdown
Bank Management System/
│
├── .gitignore                 # Specifies files and directories that should be ignored by Git
├── LICENSE                    # Open-source MIT license for the project
├── README.md                  # Project description, installation, usage, and details
├── Makefile                   # Instructions for building, cleaning and testing the project
├── build/                     # Directory for future build artifacts
│
├── data/                       # Directory containing data files (accounts.json, accounts.csv)
│   ├── accounts.json
│   └── accounts.csv
│
├── include/                    # Header files
│   ├── json.hpp                # JSON library (external)
│   └── user.h                  # User class definition
│
├── src/                        # Source files
│   └── user.cpp                # User class implementation
│ 
├── tests/
│   ├── catch.hpp               # Catch2 single header file
│   └── user_test.cpp           # Comprehensive Unit Testing
│
└── main.cpp                    # Main program entry point
```


## 🛠️ **Code Explanation**

### **🔹 `User` Class (user.h & user.cpp)**
- **Private Members**
  - `account_number`, `user_name`, `account_balance`, `account_type`
- **Public Methods**
  - `createAccount()` → Takes user input & generates account.
  - `displayAccount()` → Prints details of the account.
  - `deposit(double amount)` → Adds money to the account.
  - `withdraw(double amount)` → Deducts money from the account.
  - `modifyAccount()` → Changes name & type of the account.
  - `deleteAccount()` → Removes account data from the storage.
  - `toJson()` → Converts the user object to a JSON format.
  - `saveToJson()` → Saves all accounts to `data/accounts.json`.
  - `loadFromJson()` → Reads account data from JSON and updates the `users` list.
  - `exportToCSV()` → Exports all account data to `data/accounts.csv`.

### **🔹 `getCurrentDate()` Function**
- Returns the current date in `YYYYMMDD` format, which is used to generate unique account numbers by combining it with a static counter.

### **🔹 Static Counter**
- A **static counter** is used to generate unique account numbers. This ensures that each account number is distinct and incremented automatically with every new account creation.


## 📂 **Data Storage Formats**

### **🔹 JSON File Format (`data/accounts.json`)**
```json
[
    {
        "account_number": "0000202502261",
        "user_name": "John Doe",
        "account_balance": 1000.50,
        "account_type": "Savings"
    }
]
```

### **🔹 CSV File Format (`data/accounts.csv`)**
```csv
Account Number,Name,Balance,Type
0000202502261,John Doe,1000.50,Savings
```


## ❌ **Error Handling**
✔ **Invalid Inputs** → If incorrect data is entered, prompts reappear for correction.  
✔ **Insufficient Balance** → Withdrawals are blocked if the account has insufficient funds.  
✔ **File Errors** → If JSON/CSV files fail to open, errors are displayed.


## 🔧 **Industry Readiness & Best Practices**
- **Memory Efficiency**  
  ✅ Uses a global `vector<User>` to store all users, avoiding redundant data loading.  
  ✅ A **static counter** for unique account number generation ensures efficient handling without conflicts.

- **Modern C++ Practices**  
  ✅ Structured serialization of objects using **nlohmann/json**.  
  ✅ **RAII principles**: Destructor ensures proper memory management.  
  ✅ No raw pointers—uses **smart memory management**.

- **Scalability & Maintainability**  
  ✅ **Enum-based account types**: Future-proof design with extendable account types.  
  ✅ **Global `unordered_map<Type, std::string>`** allows for efficient lookup of account types.  
  ✅ The code avoids dependency on compiler-specific features, ensuring broader compatibility.

- **Performance Not Sacrificed**  
  ✅ Efficient handling of large datasets using **JSON** for storage.  
  ✅ Optimized file I/O with stream-based handling of file operations.


## 👥 **Contribution Guidelines**
✅ Fork the repository.  
✅ Make changes in a separate branch.  
✅ Submit a pull request (PR) with a proper description of your changes.



## 📜 **License**
This project is **open-source** under the **MIT License**.


## 🏆 **Credits & Authors**
👨‍💻 **Developed By:** Kreesh Modi  
🎓 **IIT Kharagpur | Mechanical Engineering**  




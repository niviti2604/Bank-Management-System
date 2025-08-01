#include "user.h"

using namespace std;

int main() {
    vector<User> users = User::loadFromJson();  // Load users from JSON at the start

    int choice;
    do {
        cout << "\n==== WELCOME TO BANK MANAGEMENT SYSTEM ====\n";
        cout << "1. Create Account\n";
        cout << "2. Display Account\n";
        cout << "3. Modify Account\n";
        cout << "4. Delete Account\n";
        cout << "5. Deposit Money\n";
        cout << "6. Withdraw Money\n";
        cout << "7. Export Accounts to CSV\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                User newUser;
                newUser.createAccount();
                users.push_back(newUser);  // Update local users list
                break;
            }
            case 2: {
                string accNumber;
                cout << "Enter Account Number: ";
                cin >> accNumber;

                auto it = find_if(users.begin(), users.end(), [&](const User& u) {
                    return u.getAccountNumber() == accNumber;
                });

                if (it != users.end()) {
                    it->displayAccount();
                } else {
                    cout << "Account Not Found!" << endl;
                }
                break;
            }
            case 3: {
                string accNumber;
                cout << "Enter Account Number: ";
                cin >> accNumber;

                auto it = find_if(users.begin(), users.end(), [&](const User& u) {
                    return u.getAccountNumber() == accNumber;
                });

                if (it != users.end()) {
                    it->modifyAccount();
                } else {
                    cout << "Account Not Found!" << endl;
                }
                break;
            }
            case 4: {
                string accNumber;
                cout << "Enter Account Number: ";
                cin >> accNumber;

                auto it = find_if(users.begin(), users.end(), [&](const User& u) {
                    return u.getAccountNumber() == accNumber;
                });

                if (it != users.end()) {
                    it->deleteAccount();
                    users.erase(it);  // Remove from vector
                } else {
                    cout << "Account Not Found!" << endl;
                }
                break;
            }
            case 5: {
                string accNumber;
                double amount;
                cout << "Enter Account Number: ";
                cin >> accNumber;
                cout << "Enter Amount to Deposit: ";
                cin >> amount;

                auto it = find_if(users.begin(), users.end(), [&](const User& u) {
                    return u.getAccountNumber() == accNumber;
                });

                if (it != users.end()) {
                    it->deposit(amount);
                } else {
                    cout << "Account Not Found!" << endl;
                }
                break;
            }
            case 6: {
                string accNumber;
                double amount;
                cout << "Enter Account Number: ";
                cin >> accNumber;
                cout << "Enter Amount to Withdraw: ";
                cin >> amount;

                auto it = find_if(users.begin(), users.end(), [&](const User& u) {
                    return u.getAccountNumber() == accNumber;
                });

                if (it != users.end()) {
                    it->withdraw(amount);
                } else {
                    cout << "Account Not Found!" << endl;
                }
                break;
            }
            case 7: {
                User::exportToCSV(users);
                break;
            }
            case 8:
                cout << "Exiting... Have a Nice Day!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 8);

    return 0;
}

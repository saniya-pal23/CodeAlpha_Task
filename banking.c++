#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Bank {
private:
    string name;
    string accountType;
    long accountNumber;
    float balance;

public:
    // Create account
    void createAccount() {
        cout << "Enter account holder's name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter account number: ";
        cin >> accountNumber;

        cout << "Enter account type (Saving/Current): ";
        cin >> accountType;

        cout << "Enter initial deposit amount: ?";
        cin >> balance;

        cout << "\nAccount created successfully!\n";
    }

    // Deposit money
    void deposit() {
        float amount;
        cout << "Enter amount to deposit: ?";
        cin >> amount;

        if (amount > 0) {
            balance += amount;
            cout << "?" << amount << " deposited successfully.\n";
        } else {
            cout << "Invalid deposit amount.\n";
        }
    }

    // Withdraw money
    void withdraw() {
        float amount;
        cout << "Enter amount to withdraw: ?";
        cin >> amount;

        if (amount <= 0) {
            cout << "Invalid withdrawal amount.\n";
        } else if (amount > balance) {
            cout << "Insufficient balance.\n";
        } else {
            balance -= amount;
            cout << "?" << amount << " withdrawn successfully.\n";
        }
    }

    // Display account details
    void display() const {
        cout << "\n--- Account Information ---\n";
        cout << "Name: " << name << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Balance: ?" << fixed << setprecision(2) << balance << endl;
    }
};

int main() {
    Bank account;
    int choice;

    do {
        cout << "\n========== BANK MENU ==========\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Display Account Info\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                account.createAccount();
                break;
            case 2:
                account.deposit();
                break;
            case 3:
                account.withdraw();
                break;
            case 4:
                account.display();
                break;
            case 5:
                cout << "Thank you for using our banking system.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}


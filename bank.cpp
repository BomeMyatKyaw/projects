#include <iostream>
using namespace std;

const int MAX_ACC = 100;
int accountNumbers[MAX_ACC];
double accountBalances[MAX_ACC];
int numAccounts = 0;

void createAccount() {
    if (numAccounts < MAX_ACC) {
        int accountNumber;
        double initialBalance;
        
        cout << "Enter account number: ";
        cin >> accountNumber;
        
        for (int i = 0; i < numAccounts; i++) {
            if (accountNumbers[i] == accountNumber) {
                cout << "Account already exists." << endl;
                return;
            }
        }

        cout << "Enter initial balance: $";
        cin >> initialBalance;
        
        accountNumbers[numAccounts] = accountNumber;
        accountBalances[numAccounts] = initialBalance;
        numAccounts++;

        cout << "Account created successfully." << endl;
    } else {
        cout << "Maximum number of accounts reached." << endl;
    }
}

void displayBalance() {
    int accountNumber;
    cout << "Enter account number: ";
    cin >> accountNumber;

    for (int i = 0; i < numAccounts; i++) {
        if (accountNumbers[i] == accountNumber) {
            cout << "Account Balance: $" << accountBalances[i] << endl;
            return;
        }
    }

    cout << "Account not found." << endl;
}

void deposit() {
    int accountNumber;
    double amount;

    cout << "Enter account number: ";
    cin >> accountNumber;

    for (int i = 0; i < numAccounts; i++) {
        if (accountNumbers[i] == accountNumber) {
            cout << "Enter amount to deposit: $";
            cin >> amount;
            
            accountBalances[i] += amount;
            cout << "Deposit successful. New balance: $" << accountBalances[i] << endl;
            return;
        }
    }

    cout << "Account not found." << endl;
}

void withdraw() {
    int accountNumber;
    double amount;

    cout << "Enter account number: ";
    cin >> accountNumber;

    for (int i = 0; i < numAccounts; i++) {
        if (accountNumbers[i] == accountNumber) {
            cout << "Enter amount to withdraw: $";
            cin >> amount;

            if (accountBalances[i] >= amount) {
                accountBalances[i] -= amount;
                cout << "Withdrawal successful. New balance: $" << accountBalances[i] << endl;
            } else {
                cout << "Insufficient balance." << endl;
            }
            return;
        }
    }

    cout << "Account not found." << endl;
}

int main() {
    int choice;
    
    do {
        cout << "Bank Management System" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Display Balance" << endl;
        cout << "3. Deposit" << endl;
        cout << "4. Withdraw" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                displayBalance();
                break;
            case 3:
                deposit();
                break;
            case 4:
                withdraw();
                break;
            case 5:
                cout << "Exiting program. Thank you!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}

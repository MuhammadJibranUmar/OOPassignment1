#include <iostream>
#include <string>

using namespace std;

class Account {
public:
    Account() : accountNumber(0), title(""), balance(0) {} // Default constructor

    Account(int accountNo, string accountTitle, int accountBalance) {
        accountNumber = accountNo;
        title = accountTitle;
        balance = accountBalance;
    }

    void getDetails() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Title: " << title << endl;
        cout << "Balance: " << balance << endl;
    }

    unsigned int getAccountNumber() const {
        return accountNumber;
    }

    void setTitle(const string& newTitle) {
        title = newTitle;
    }

    void setBalance(int newBalance) {
        balance = newBalance;
    }

private:
    unsigned int accountNumber;
    string title;
    int balance;
};

class BankSystem {
public:
    BankSystem() : count(0) {}

    void addAccount(int accountNo, string title, int balance) {
        if (count < 100) {
            account[count++] = Account(accountNo, title, balance);
            cout << "Account added successfully!!\n";
        } else {
            cout << "Cannot add more accounts. Limit reached.\n";
        }
    }

    void deleteAccount(int accountNo) {
        bool found = false;
        for (int i = 0; i < count; i++) {
            if (account[i].getAccountNumber() == accountNo) {
                for (int j = i; j < count - 1; j++) {
                    account[j] = account[j + 1];
                }
                count--;
                found = true;
                cout << "Account deleted Successfully!!\n";
                break;
            }
        }
        if (!found) {
            cout << "Error!! \nAccount Not Found. \n";
        }
    }

    void modifyAccount(int accountNo, string title, int balance) {
        bool found = false;
        for (int i = 0; i < count; i++) {
            if (account[i].getAccountNumber() == accountNo) {
                account[i].setTitle(title);
                account[i].setBalance(balance);
                found = true;
                cout << "Account Modified Successfully!!\n";
                break;
            }
        }
        if (!found) {
            cout << "Account Not Found!!\n";
        }
    }

    void displayAccounts() {
        for (int i = 0; i < count; i++) {
            account[i].getDetails();
        }
    }

private:
    Account account[100];
    int count;
};

void menu() {
    cout << "Main Menu\n";
    cout << "[1]. Add Account\n";
    cout << "[2]. Delete Account\n";
    cout << "[3]. Modify Account\n";
    cout << "[4]. Display Accounts\n";
    cout << "[5]. Exit\n";
    cout << "Enter your Choice: ";
}

void setDetails(BankSystem &bank) {
    int accountNo;
    string title;
    int balance;

    cout << "Enter Account Number: ";
    cin >> accountNo;

    cout << "Enter Account Title: ";
    cin.ignore(); // Clear input buffer
    getline(cin, title);

    cout << "Enter Balance: ";
    cin >> balance;

    bank.addAccount(accountNo, title, balance);
}

int main() {
    BankSystem bank;
    int choice;
    int modAccountNo;
    string modTitle;
    int modBalance;

    do {
        menu();
        cin >> choice;

        switch (choice) {
            case 1:
                setDetails(bank);
                break;
            case 2:
                int accountNo;
                cout << "Enter Account Number to Delete: ";
                cin >> accountNo;
                bank.deleteAccount(accountNo);
                break;
            case 3:
                cout << "Enter Account Number to Modify: ";
                cin >> modAccountNo;
                cout << "Enter New Title: ";
                cin.ignore(); // Clear input buffer
                getline(cin, modTitle);
                cout << "Enter New Balance: ";
                cin >> modBalance;
                bank.modifyAccount(modAccountNo, modTitle, modBalance);
                break;
            case 4:
                bank.displayAccounts();
                break;
            case 5:
                cout << "Exiting...";
                break;
            default:
                cout << "Invalid choice! Please enter a valid option.\n";
                break;
        }
    } while (choice != 5);

    return 0;
}
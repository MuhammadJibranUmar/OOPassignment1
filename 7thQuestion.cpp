#include <iostream>
using namespace std;

const int MAX_ACCOUNTS = 100;

class Account{
    public:
        
        int accountNumber;
        
        Account(){
            accountNumber = 0;
            accountBalance = 0;
        }

        void addAccount(int number, string title, double balance){
            accountNumber = number;
            accountTitle = title;
            accountBalance = balance;

            cout << "Account created successfully!!\n";
        }

        void modAccount(string title, double balance){
            accountTitle = title;
            accountBalance = balance;

            cout << "Account Modified successfully!!!\n";
        }
        void creditAmount(double amount){
            accountBalance += amount;

            cout << "Balance updated successfully!!\n";
        }

        void debitAmount(double amount){
            if (amount <= accountBalance)
            {
                accountBalance -= amount;
                cout << "Balance updated successfully!!\n";
            } else
            {
                cout << "Insufficient Balance!!\n";
            }
        }

        void dispalyInfo(){
            cout << "Account Number: " << accountNumber << endl;
            cout << "Account Title: " << accountTitle << endl;
            cout << "Account Balance: " << accountBalance << endl;
            cout << "-------------\n";
        }
    private:
        
        string accountTitle;
        double accountBalance;
};

class BankSystem
{
    public:
        BankSystem(){
            count = 0;
        }

        void accountMenu(){
            cout << "Account Menu\n";
            cout << "[1]. Credit Amount\n";
            cout << "[2]. Debit Amount\n";
            cout << "[3]. Modify Account\n";
            cout << "[4]. Display Info\n";
            cout << "[5]. Logout";
            cout << "\nEnter choice: ";
        }

        void addAccount(){
            int accountNum;
            cout << "Enter Account Number: ";
            cin >> accountNum;

            for (int i = 0; i < count; i++)
            {
                if (accountNum == accounts[i].accountNumber)
                {
                    cout << "Account already exists!!\n";
                    return;
                }
            }
                    string title;
                    double balance;

                    cout << "Enter Title: ";
                    cin.ignore();
                    getline(cin, title);
                    cout << "Enter Balance: ";
                    cin >> balance;

                    accounts[count].addAccount(accountNum, title, balance);
                    count++;
            
        }

        void deleteAccount(int accountNum){

            for (int i = 0; i < count; i++)
            {
                if(accountNum == accounts[i].accountNumber){
                    for (int j = i; j < count - 1; j++)
                    {
                        accounts[j] = accounts[j+1];
                    }
                    cout << "Account Deleted successfully!!!\n";
                    count--;
                    return;
                }
            }
            cout << "Account Not Found !!!\n";
            

        }

        void modifyAccount(int accountNum){

            for (int i = 0; i < count; i++)
            {
                if (accountNum == accounts[i].accountNumber)
                {
                    string title;
                    double balance;

                    cout << "Enter Title: ";
                    cin.ignore();
                    getline(cin, title);
                    cout << "Enter Balance: ";
                    cin >> balance;

                    accounts[i].modAccount(title, balance);
                    return;
                }
            }
            cout << "Account does not exists!!!\n";
        }

        void loginAccount(){
            int accountNum;
            cout << "Enter Account Number: ";
            cin >> accountNum;

            for (int i = 0; i < count; i++)
            {
                if (accountNum == accounts[i].accountNumber)
                {
                    cout << "Login Successful!!\n";
                    char accountOption;
                    double amount;
                    do
                    {
                        accountMenu();
                        cin >> accountOption;

                        switch (accountOption)
                        {
                        case '1':
                            cout << "Enter amount to credit: ";
                            cin >> amount;
                            accounts[i].creditAmount(amount);
                            break;
                        case '2':
                            cout << "Enter amount to withdraw: ";
                            cin >> amount;
                            accounts[i].debitAmount(amount);
                            break;
                        case '3':
                            modifyAccount(accountNum);
                            break;
                        case '4':
                            accounts[i].dispalyInfo();
                            break;
                        case '5':
                            cout << "Logged out!!!\n";
                            break;
                        default:
                            cout << "Invalid Option!! \n";
                            break;
                        }
                    } while (accountOption != '5');
                    return;
                }
                
            }
            cout << "Account not found!!!\n";
            
        }

        void displayAccounts(){
            for (int i = 0; i < count; i++)
            {
                accounts[i].dispalyInfo();
            }
            
        }
        
    private:
        Account accounts[MAX_ACCOUNTS];
        int count;
};

void bankMenu(){
    cout << "Menu\n";
    cout << "[1]. Add Account\n";
    cout << "[2]. Modify Account\n";
    cout << "[3]. Delete Account\n";
    cout << "[4]. Display Accounts\n";
    cout << "[5]. Login to certain Account\n";
    cout << "[6]. Exit\n";
    cout << "\nEnter choice: ";
}

int main(){
    BankSystem bank;
    char bankOption;
    int accountNum;
    do
    {
        bankMenu();
        
        cin >> bankOption;

        switch (bankOption)
        {
        case '1':
            bank.addAccount();
            break;
        case '2':
            cout << "Enter Account Number: ";
            cin >> accountNum;

            bank.modifyAccount(accountNum);
            break;
        case '3':
            cout << "Enter Account Number: ";
            cin >> accountNum;
            bank.deleteAccount(accountNum);
            break;
        case '4':
            bank.displayAccounts();
            break;
        case '5':
            bank.loginAccount();
            break;
        case '6':
            cout << "Exiting!!!\n";
            break;
        default:
            cout << "Invalid option!!!\n";
            break;
        }
    } while (bankOption != '6');
    
    return 0;
}

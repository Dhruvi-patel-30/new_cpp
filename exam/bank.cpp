#include <iostream>
using namespace std;

class BankAccount
{
private:
    int accountNumber;
    double balance;
    string ownerName;

public:
   
    BankAccount(int accNo, string name, double bal)
    {
        accountNumber = accNo;
        ownerName = name;
        balance = bal;
    }

    void credit(double amount)
    {
        balance += amount;
        cout << "Amount Credited: " << amount << endl;
    }

    void debit(double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
            cout << "Amount Debited: " << amount << endl;
        }
        else
        {
            cout << "Insufficient Balance!" << endl;
        }
    }

    void displayBalance()
    {
        cout << "\nAccount Number: " << accountNumber << endl;
        cout << "Owner Name: " << ownerName << endl;
        cout << "Current Balance: " << balance << endl;
    }
};

int main()
{
    int accNo;
    string name;
    double bal, amount;

    cout << "Enter Account Number: ";
    cin >> accNo;

    cin.ignore();

    cout << "Enter Owner Name: ";
    getline(cin, name);

    cout << "Enter Initial Balance: ";
    cin >> bal;

    BankAccount acc(accNo, name, bal);

    acc.displayBalance();

    cout << "\nEnter amount to Credit: ";
    cin >> amount;
    acc.credit(amount);

    acc.displayBalance();

    cout << "\nEnter amount to Debit: ";
    cin >> amount;
    acc.debit(amount);

    acc.displayBalance();

}
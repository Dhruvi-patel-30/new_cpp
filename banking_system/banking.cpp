#include <iostream>
using namespace std;

class BankAccount
{
protected:
    int accountNumber;
    string accountHolderName;

private:
    double balance;

public:
    BankAccount(int accNo, string name, double bal)
    {
        accountNumber = accNo;
        accountHolderName = name;
        balance = bal;
    }

    virtual void deposit(double amount)
    {
        balance += amount;
        cout << "\nDeposit Successful!";
    }

    virtual void withdraw(double amount)
    {
        if(amount <= balance)
        {
            balance -= amount;
            cout << "\nWithdrawal Successful!";
        }
        else
        {
            cout << "\nInsufficient Balance!";
        }
    }

    double getBalance()
    {
        return balance;
    }

    void setBalance(double bal)
    {
        balance = bal;
    }

    virtual void displayAccountInfo()
    {
        cout << "\nAccount Number : " << accountNumber;
        cout << "\nAccount Holder : " << accountHolderName;
        cout << "\nBalance : " << balance << endl;
    }

    virtual void calculateInterest()
    {
        cout << "\nInterest calculation not available!";
    }

    virtual ~BankAccount() {}
};


class SavingsAccount : public BankAccount
{
private:
    double interestRate;

public:
    SavingsAccount(int accNo, string name, double bal, double rate)
        : BankAccount(accNo, name, bal)
    {
        interestRate = rate;
    }

    void calculateInterest() override
    {
        double interest = getBalance() * interestRate / 100;
        cout << "\nSavings Interest : " << interest;
    }
};

class CheckingAccount : public BankAccount
{
private:
    double overdraftLimit;

public:
    CheckingAccount(int accNo, string name, double bal, double limit)
        : BankAccount(accNo, name, bal)
    {
        overdraftLimit = limit;
    }

    void withdraw(double amount) override
    {
        if(amount <= getBalance() + overdraftLimit)
        {
            setBalance(getBalance() - amount);
            cout << "\nWithdrawal Successful!";
        }
        else
        {
            cout << "\nOverdraft Limit Exceeded!";
        }
    }

    void checkOverdraft()
    {
        cout << "\nOverdraft Limit : " << overdraftLimit;
    }
};

class FixedDepositAccount : public BankAccount
{
private:
    int term;

public:
    FixedDepositAccount(int accNo, string name, double bal, int t)
        : BankAccount(accNo, name, bal)
    {
        term = t;
    }

    void calculateInterest() override
    {
        double rate = 7;
        double interest = getBalance() * rate * term / (12 * 100);
        cout << "\nFixed Deposit Interest : " << interest;
    }
};

int main()
{
    SavingsAccount s1(101, "Dhruvi", 10000, 6);
    CheckingAccount c1(102, "Meet", 5000, 2000);
    FixedDepositAccount f1(103, "Krishna", 50000, 12);

    BankAccount* acc = NULL;

    int choice, accType;
    double amount;

    do
    {
        cout << "\n\n===== BANK MENU =====";
        cout << "\n1. Select Account";
        cout << "\n2. Deposit";
        cout << "\n3. Withdraw";
        cout << "\n4. Display Info";
        cout << "\n5. Calculate Interest";
        cout << "\n6. Exit";

        cout << "\nEnter Choice : ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            cout << "\nSelect Account Type:";
            cout << "\n1. Savings";
            cout << "\n2. Checking";
            cout << "\n3. Fixed Deposit";
            cout << "\nEnter : ";
            cin >> accType;

            if(accType == 1) acc = &s1;
            else if(accType == 2) acc = &c1;
            else if(accType == 3) acc = &f1;
            else cout << "\nInvalid Account!";
            break;

        case 2:
            if(acc == NULL) { cout << "\nSelect account first!"; break; }
            cout << "Enter Amount : ";
            cin >> amount;
            acc->deposit(amount);
            break;

        case 3:
            if(acc == NULL) { cout << "\nSelect account first!"; break; }
            cout << "Enter Amount : ";
            cin >> amount;
            acc->withdraw(amount);
            break;

        case 4:
            if(acc == NULL) { cout << "\nSelect account first!"; break; }
            acc->displayAccountInfo();
            break;

        case 5:
            if(acc == NULL) { cout << "\nSelect account first!"; break; }
            acc->calculateInterest();
            break;

        case 6:
            cout << "\nThank You!";
            break;

        default:
            cout << "\nInvalid Choice!";
        }

    } while(choice != 6); 
}
#include <iostream>
#include <vector>
using namespace std;

struct data
{
    string name;        
    int accNo;        
    string accType;     
    float balance;   
};

vector<data> accounts;

class Bank
{
public:
    string accName;
    int accNo;
    string accountType;

public:
    void setData();
    void display();
};

void Bank::setData()
{
    cout<<endl;
    cout << "Enter Account  Name:  "<< endl;
    cin >> accName;

    cout << "Enter Account Number: "<<endl;
    cin >>accNo;

    cout << "Enter Account Type (Saving/Current): "<<endl;
    cin >> accountType;
}

class AccDetails : public Bank
{
public:
    void SetDetails()
    {
        setData();
    }
};

class AccountSetup : public AccDetails
{
public:
    float balance;

    void createAccount()
    {
        SetDetails();

        cout << "Enter Opening Balance: ";
        cin >> balance;

        accounts.push_back({accName, accNo, accountType, balance});
       cout<<endl;
        cout << "------- Account Created Successfully -------";
    }

    void displayAll()
    {
        cout << "\n S.No    Name        Acc No      Type      Balance\n";

        int i = 1;
        for (data a : accounts)
        {
            cout << " " << i++ << ".     "
                 << a.name << "        "
                 << a.accNo << "        "
                 << a.accType << "        "
                 << a.balance << endl;
        }
    }
};

class Transaction : public AccountSetup
{
public:
    int searchAccNo;
    float amount;

    void deposit()
    {
        cout << "\nEnter Account Number to Deposit: ";
        cin >> searchAccNo;

        for (data a : accounts)
        {
            if (a.accNo == searchAccNo)
            {
                cout << "Enter Amount: ";
                cin >> amount;

                a.balance += amount;

                cout << "\nAmount Deposited Successfully!\n";
                return;
            }
        }

        cout << "\nAccount Not Found!\n";
    }

    void withdraw()
    {
        cout << "\nEnter Account Number to Withdraw: ";
        cin >> searchAccNo;

        for (data a : accounts)
        {
            if (a.accNo == searchAccNo)
            {
                cout << "Enter Amount: ";
                cin >> amount;

                if (amount > a.balance)
                {
                    cout << "\nInsufficient Balance!\n";
                }
                else
                {
                    a.balance -= amount;
                    cout << "\nAmount Withdrawn Successfully!\n";
                }
                return;
            }
        }

        cout << "\nAccount Not Found!\n";
    }

    void searchAccount()
    {
        cout << "\nEnter Account Number: ";
        cin >> searchAccNo;

        for (data a : accounts)
        {
            if (a.accNo == searchAccNo)
            {
                cout << "\n--- Account Found ---\n";
                cout << "Name        : " << a.name << endl;
                cout << "Account No  : " << a.accNo << endl;
                cout << "Type        : " << a.accType << endl;
                cout << "Balance     : " << a.balance << endl;
                return;
            }
        }

        cout << "\nAccount Not Found!\n";
    }
};

int main()
{
    int ch;
    Transaction t1;

    do
    {
        cout << "\n========== BANK MENU ==========\n";
        cout << "1. Create Account\n";
        cout << "2. Show All Accounts\n";
        cout << "3. Deposit Money\n";
        cout << "4. Withdraw Money\n";
        cout << "5. Search Account\n";
        cout << "0. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            t1.createAccount();
            break;

        case 2:
            t1.displayAll();
            break;

        case 3:
            t1.deposit();
            break;

        case 4:
            t1.withdraw();
            break;

        case 5:
            t1.searchAccount();
            break;

        case 0:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (ch != 0);

    return 0;
}
#include <iostream>

using namespace std;

class bank
{
    char userName[30];
    int userAccNum;
    float userBalance;
    char typeOfAcc[30];

public:
    bank()
    {
        userAccNum = 0;
        userBalance = 0.0;
    }
    void inputIn();
    void deposit();
    void withdraw();
    void display();
};

void bank::inputIn()
{
    cout << "Welcome!" << endl;
    cout << "Please, enter the name of depositor: ";
    cin >> userName;
    cout << "Account number: ";
    cin >> userAccNum;
    cout << "Type of account: ";
    cin >> typeOfAcc;
    cout << "Please, enter amount to deposit: ";
    cin >> userBalance;
}

void bank::deposit()
{
    float amountD;
    cout << "Please, enter amount to deposit: ";
    cin >> amountD;
    userBalance += amountD;
}

void bank::withdraw()
{
    float amountW;
    cout << "Please, enter amount to withdraw: ";
    cin >> amountW;
    userBalance -= amountW;
}

void bank::display()
{
    cout << "Account details: " << endl;
    cout << "Name of depositor: " << userName << endl;
    cout << "Account number: " << userAccNum << endl;
    cout << "Type of account: " << typeOfAcc << endl;
    cout << "Current balance: " << userBalance << endl;
}

int main()
{
    bank bank1;
    int userChoice = 1;
    while (userChoice != 0)
    {
        cout << "Press '0' for exit" << endl;
        cout << "1. Create a new account" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Deposit" << endl;
        cout << "4. Account status" << endl;
        cin >> userChoice;
        switch (userChoice)
        {
        case 0:
            bank1.display();
            cout << "\nStay safe " << endl;
            break;
        case 1:
            bank1.inputIn();
            break;
        case 2:
            bank1.withdraw();
            break;
        case 3:
            bank1.deposit();
            break;
        case 4:
            bank1.display();
            break;
        default:
            cout << "Error!" << endl;
        }
    }
    return 0;
}
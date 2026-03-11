#include <iostream>
using namespace std;

//declare class for bank account
class BankAccount
{
    private:
    float balance; //balance is private 

    public: 

    BankAccount() //set balance to 0
    {
        balance = 0;
    }
// funtion for deposit, inside public so private variable balance can be accessed
    void deposit(float amount)
    {
        if(amount > 0)
        {
            balance = balance + amount;
        }
        else
        {
            cout << "Invalid amount to deposit." << endl;
        }
    }
// funtion for withdrawal, inside public so private variable balance can be accessed
    void withdraw(float amount)
    {
        if(amount > 0 && amount <= balance)
        {
            balance = balance - amount;
        }
        else
        {
            cout << "Not enough money in account. " << endl;
        }
    }
// funtion for displaying balance, inside public so private variable balance can be accessed
    void display_balance()
    {
        cout << "Current balance: $" << balance << endl;
    }

};

int main()
{// declare variables
    BankAccount account;
    float amount;
    int choice;

    
    
    //do while loop to reask the question until answer is 3 (quit)
   do
   {
        cout << "Are you looking to withdraw or deposit? (1 = deposit, 2 = withdraw, 3 = quit): ";
        cin >> choice;
        cout << endl;
        
        //switch for choice to call different fucntion depending on choice
        switch (choice)
        {
            cout << "Are you looking to withdraw or deposit? (1 = deposit, 2 = withdraw, 3 = quit): ";
            cin >> choice;

            case 1: 
            cout << "Input amount to deposit: $";
            cin >> amount;
            account.deposit(amount);
            account.display_balance();
            break;

            case 2:
            cout << "Input amount to withdraw: $";
            cin >> amount;
            account.withdraw(amount);
            account.display_balance();
            break;

            case 3:
            account.display_balance();
            cout << "Have a good day! " << endl;
            return 0;
            break;
        }
   }while(choice != 3);
   
    
   


    return 0;
}
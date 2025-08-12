#include <iostream>
using namespace std;

class ATM
 {
private:
    int accountBalance;
    int initialBalance;
    const int pin = 12345;

public:
    // Constructor
    ATM() 
    {
        initialBalance = 60000;
        accountBalance = 20000;
    }

    
    void welcomeScreen()
    {
       

        cout << "========================================\n";
        cout << "       Welcome to the ATM Service       \n";
        cout << "========================================\n\n";
    }

    // Display main menu
    void displayMenu() 
    {
        cout << "\n------ Main Menu ------\n";
        cout << "1. Enter ATM PIN\n";
        cout << "2. Help\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
    }

    // Help screen
    void helpScreen() 
    {
        cout << "\n=========== HELP SCREEN ===========\n";
        cout << "• Use this ATM to deposit, withdraw, or check balance.\n";
        cout << "• Only one attempt allowed for ATM PIN.\n";
        cout << "• Contact bank for lost card or PIN.\n";
        cout << "===================================\n";
    }

    // ATM PIN check
    bool checkPIN()
     {
        int enteredPin;
        cout << "Enter your 5-digit ATM PIN: ";
        cin >> enteredPin;

        if (enteredPin == pin) 
        {
            return true;
        } else 
        {
            cout << "\nIncorrect PIN! Access Denied. Exiting...\n";
            return false;
        }
    }

    // Operations menu
    void operationsMenu()
     {
        int choice;
        do {
            cout << "\n===== Banking Operations =====\n";
            cout << "1. Deposit\n";
            cout << "2. Withdraw\n";
            cout << "3. Check Balance\n";
            cout << "4. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    deposit();
                    break;
                case 2:
                    withdraw();
                    break;
                case 3:
                    checkBalance();
                    break;
                case 4:
                    cout << "Thank you for using the ATM. Goodbye!\n";
                    break;
                default:
                    cout << "Invalid choice. Try again.\n";
            }
        } while (choice != 4);
    }

    // Deposit amount
    void deposit()
     {
        int amount;
        cout << "Enter amount to deposit: Rs. ";
        cin >> amount;
        if (amount > 0) 
        {
            accountBalance += amount;
            cout << "Amount Deposited Successfully!\n";
            cout << "Initial Balance: Rs. " << initialBalance << endl;
            cout << "Present Balance: Rs. " << accountBalance << endl;
        } else
         {
            cout << "Invalid deposit amount.\n";
        }
    }

    // Withdraw amount
    void withdraw() 
    {
        int amount;
        cout << "Enter amount to withdraw: Rs. ";
        cin >> amount;

        if (amount <= accountBalance && amount > 0)
         {
            accountBalance -= amount;
            cout << "Withdrawal Successful!\n";
            cout << "Remaining Balance: Rs. " << accountBalance << endl;
        } else
        {
            cout << "Unsuccessful Withdrawal! Insufficient balance or invalid amount.\n";
        }
    }

    // Check balance
    void checkBalance() 
    {
        cout << "Your Current Account Balance is: Rs. " << accountBalance << endl;
    }
};

// ======= Main Function =======
int main() {
    ATM atm; // Object creation (calls constructor)

    atm.welcomeScreen(); // Step 1

    int mainChoice;
    atm.displayMenu();   // Step 2
    cin >> mainChoice;

    if (mainChoice == 1) 
    {
        if (atm.checkPIN())
         {
            atm.operationsMenu();
        }
    } else if (mainChoice == 2) 
    {
        atm.helpScreen();
    } else
     {
        cout << "Exiting the ATM. Have a nice day!\n";
    }

    return 0;
}

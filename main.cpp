#include "BankAccount.h"

int main() {

    int choice;

    do {
        cout << "\n================================";
        cout << "\n BANK MANAGEMENT SYSTEM";
        cout << "\n================================";

        cout << "\n1. Create Account";
        cout << "\n2. Display All Accounts";
        cout << "\n3. Search Account";
        cout << "\n4. Delete Account";
        cout << "\n5. Exit";

        cout << "\n\nEnter Choice: ";
        cin >> choice;

        switch(choice) {

            case 1: {
                BankAccount acc;
                acc.createAccount();
                acc.writeToFile();
                cout << "\nAccount Created Successfully!\n";
                break;
            }

            case 2:
                BankAccount::displayAllAccounts();
                break;

            case 3: {
                int accNo;
                cout << "Enter Account Number: ";
                cin >> accNo;
                BankAccount::searchAccount(accNo);
                break;
            }

            case 4: {
                int accNo;
                cout << "Enter Account Number: ";
                cin >> accNo;
                BankAccount::deleteAccount(accNo);
                break;
            }

            case 5:
                cout << "\nThank You!\n";
                break;

            default:
                cout << "\nInvalid Choice!";
        }

    } while(choice != 5);

    return 0;
}

#include "BankAccount.h"

void BankAccount::createAccount() {
    cout << "Enter Account Number: ";
    cin >> accountNumber;

    cin.ignore();
    cout << "Enter Customer Name: ";
    getline(cin, name);

    cout << "Enter Initial Balance: ";
    cin >> balance;
}

void BankAccount::displayAccount() const {
    cout << "\nAccount Number: " << accountNumber;
    cout << "\nCustomer Name: " << name;
    cout << "\nBalance: " << balance << endl;
}

int BankAccount::getAccountNumber() const {
    return accountNumber;
}

double BankAccount::getBalance() const {
    return balance;
}

void BankAccount::deposit(double amount) {
    balance += amount;
}

bool BankAccount::withdraw(double amount) {
    if(amount > balance)
        return false;

    balance -= amount;
    return true;
}

void BankAccount::writeToFile() {
    ofstream file("accounts.txt", ios::app);

    file << accountNumber << ","
         << name << ","
         << balance << endl;

    file.close();
}

void BankAccount::displayAllAccounts() {
    ifstream file("accounts.txt");
    string line;

    cout << "\n===== All Accounts =====\n";

    while(getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}

void BankAccount::searchAccount(int accNo) {
    ifstream file("accounts.txt");

    string line;
    bool found = false;

    while(getline(file, line)) {
        size_t pos = line.find(',');

        int acc = stoi(line.substr(0, pos));

        if(acc == accNo) {
            cout << "\nFound Account:\n";
            cout << line << endl;
            found = true;
        }
    }

    if(!found)
        cout << "\nAccount Not Found!\n";

    file.close();
}

void BankAccount::deleteAccount(int accNo) {
    ifstream file("accounts.txt");
    ofstream temp("temp.txt");

    string line;

    while(getline(file, line)) {
        size_t pos = line.find(',');

        int acc = stoi(line.substr(0, pos));

        if(acc != accNo)
            temp << line << endl;
    }

    file.close();
    temp.close();

    remove("accounts.txt");
    rename("temp.txt", "accounts.txt");

    cout << "\nAccount Deleted Successfully!\n";
}

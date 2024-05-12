#include "account.h"
#include <iostream>
#include <string>
#include <list>

list<Account>::iterator findID(list<Account>& accounts, int id);

int main()
{
    int run = 0;
    int ID = 0;
    int id;
    string name;
    float balance{};
    float deposit;
    float withdraw;
    list<Account> accounts{};
    Account accountA(ID, name, balance);
    int choice;
    while (run != 1) {
        cout << "\nAccount Menu:\n0. Quit Program\n1. Display Account Information\n2. Add a deposit to an account\n3. Withdraw from an account\n4. Add new account\n5. Find account by ID\nYour choice: ";
        cin >> choice;
        if (choice == 1) {
            for (list<Account>::iterator account = accounts.begin(); account != accounts.end(); account++) {
                (*account).display_account();
            }
        }
        else if (choice == 2) {
            cout << "ID of the account to find: ";
            cin >> id;
            list<Account>::iterator it;
            it = findID(accounts, id);
            if (it != accounts.end()) {
                cout << "Account found: ";
                it->display_account();
                cout << "Amount to deposit: ";
                cin >> deposit;
                it->deposit(deposit);
            }
            else {
                cout << "Account not found.\n";
            }
        }
        else if (choice == 3) {
            cout << "ID of the account to find: ";
            cin >> id;
            list<Account>::iterator it;
            it = findID(accounts, id);
            if (it != accounts.end()) {
                cout << "Account found: ";
                it->display_account();
                cout << "Amount to withdraw: ";
                cin >> withdraw;
                it->withdraw(withdraw);
            }
            else {
                cout << "Account not found.\n";
            }
        }
        else if (choice == 4) {
            cout << "Enter the name: ";
            cin >> name;
            cout << "Enter the balance: ";
            cin >> balance;
            Account accountA(ID, name, balance);
            accounts.push_back(accountA);
            ID += 1;
        }
        else if (choice == 5) {
            cout << "ID of the account to find: ";
            cin >> id;
            list<Account>::iterator it;
            it = findID(accounts, id);
            if (it != accounts.end()){
                cout << "Account found: ";
                it->display_account();
            }
            else {
                cout << "Account not found.\n";
            }
        }
        else if (choice == 0) {
            run = 1;
        }
    }
}

list<Account>::iterator findID(list<Account>& accounts, int id) {
    list<Account>::iterator it;
    for (it = accounts.begin(); it != accounts.end(); it++) {
        if (it->get_id() == id) {
            return it;
        }
    }
    return it;
}
// Account.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "account.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

Account::Account() :accountID(0), accountName(""), accountBalance(0) {}

Account::Account(int ID, string Name, float accountBalance):accountID(ID), accountName(Name), accountBalance(accountBalance){}

void Account::display_account()
{
	cout << "Account ID: " << accountID << " Name: " << accountName << " Balance: $" << fixed << setprecision(2) << accountBalance << "\n";
}

void Account::deposit(float addition)
{
	accountBalance = accountBalance + addition;
}

void Account::withdraw(float subtraction)
{
	accountBalance = accountBalance - subtraction;
}

int Account::get_id() const
{
	return accountID;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

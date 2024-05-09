#include "Calc.h"
#include <iostream>

using namespace std;

int main()
{
    int run = 0;
    float i1 = 0;
    float i2 = 0;
    float a = 0;
    char av;
    cout << "Enter first variable: ";
    cin >> i1;
    cout << "Enter second variable: ";
    cin >> i2;
    Calc calc1(i1, i2, a);
    int choice;
    while (run != 1) {
        cout << "\nCalculation Menu:\n0. Quit Program\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Absolute Value\nYour choice: ";
        cin >> choice;
        if (choice == 1) {
            cout << "Adding\n";
            calc1.Addition();
        }
        else if (choice == 2) {
            cout << "Subtracting\n";
            calc1.Subtraction();
        }
        else if (choice == 3) {
            cout << "Multiplying\n";
            calc1.Multiplication();
        }
        else if (choice == 4) {
            cout << "Dividing\n";
            calc1.Division();
        }
        else if (choice == 5) {
            cout << "Which number would you like to get the absolute value for, x or y?";
            cin >> av;
            cout << "Getting absolute value\n";
            if (av == 'x') {
                calc1.Absolute_ValueX();
            }
            else if (av == 'y') {
                calc1.Absolute_ValueY();
            }
        }
        else if (choice == 0) {
            run = 1;
        }
        calc1.Display_Answer();
    }
}
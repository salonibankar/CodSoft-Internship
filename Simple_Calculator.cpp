#include <bits/stdc++.h>
using namespace std;

int main()
{
    long double num1, num2;
    int ch;
    char choice;

    do
    {
        cout << "Enter first number = " << endl;
        cin >> num1;
        cout << "Enter second number =" << endl;
        cin >> num2;

        cout << "Select operation : " << endl;
        cout << " 1.Addition" << endl
             << " 2.Substraction" << endl
             << " 3.Multiplication" << endl
             << " 4.Division" << endl;
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Addition : " << endl;
            cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
            break;

        case 2:
            cout << "Substraction : " << endl;
            cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
            break;

        case 3:
            cout << "Multiplication : " << endl;
            cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
            break;

        case 4:
            cout << "Division : " << endl;
            if (num2 != 0)
                cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
            else
                cout << "Can't divide by zero" << endl;
            break;

        default:
            cout << "The option selected is not valid" << endl;
        }
        cout << "Want to perform more operations ? (Y/N)" << endl;
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    char ch;
    do
    {
        srand(time(0));
        int randomInt = rand() % 101;

        cout << "num : " << randomInt << endl;

        cout << "-----------------------NUMBER GUESSING GAME------------------------" << endl;
        cout << " RULES \n"
             << endl;
        cout << " - You will be given 5 chances in total to guess the correct number\n"
             << endl;
        cout << " - The number lies in the range 0-100\n"
             << endl;
        cout << " You WIN if you guess the number in 5 chances else you LOSE !! \n\n"
             << endl;

        int choice;

        bool satisfied;
        for (int i = 0; i < 5; i++)
        {
            cout << "Enter your " << i + 1 << " choice : ";
            cin >> choice;
            if (choice == randomInt)
            {
                cout << "The guess you made matches the random number " << randomInt << endl;
                cout << "You WON !!\n"
                     << endl;
                satisfied = true;
                break;
            }
            else
            {
                if (choice < randomInt)
                {
                    if (i < 4)
                    {
                        cout << "Try guessing a greater number !!\n"
                             << endl;
                    }
                }
                else
                {
                    if (i < 4)
                    {
                        cout << "Try guessing a smaller number !!\n"
                             << endl;
                    }
                }
            }
        }

        if (!satisfied)
        {
            cout << " OOPS! You are out of chances, you LOSE !!\n"
                 << endl;
        }
        cout << "Do you want to play again (Y/y)?\n " << endl;
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    return 0;
}
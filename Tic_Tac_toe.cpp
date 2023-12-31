#include <iostream>
using namespace std;

string n1;
string n2;
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char sym = 'x';
int r, c;
bool draw;
char ans;
bool result();

void start()
{
    cout << "   |   |   " << endl;
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "___|___|___" << endl;
    cout << "   |   |   " << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "___|___|___" << endl;
    cout << "   |   |   " << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
    cout << "   |   |   " << endl;
}

void choice()
{
    int num;
    if (sym == 'x')
    {
        cout << n1 << "'s turn. Please select a choice: " << endl;
        cin >> num;
    }
    else if (sym == 'o')
    {
        cout << n2 << "'s turn. Please select a choice: " << endl;
        cin >> num;
    }

    if (num >= 1 && num <= 9)
    {
        r = (num - 1) / 3;
        c = (num - 1) % 3;

        if (board[r][c] != 'x' && board[r][c] != 'o')
        {
            if (sym == 'x')
            {
                board[r][c] = 'x';
                sym = 'o';
            }

            else if (sym == 'o')
            {
                board[r][c] = 'o';
                sym = 'x';
            }
        }
        else
        {
            cout << "Invalid Choice! Cell already taken." << endl;
            choice();
        }
    }
    else
    {
        cout << "Invalid Choice! Please enter a number between 1 and 9." << endl;
        choice();
    }

    // start();
}

bool result()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] ||
            board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return true;
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] ||
        board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return true;

    for (int row = 0; row < 3; row++)
    {
        for (int column = 0; column < 3; column++)
        {
            if (board[row][column] != 'x' && board[row][column] != 'o')
                return false;
        }
    }

    draw = true;
    return true;
}

int main()
{
    do
    {

        board[0][0] = '1';
        board[0][1] = '2';
        board[0][2] = '3';
        board[1][0] = '4';
        board[1][1] = '5';
        board[1][2] = '6';
        board[2][0] = '7';
        board[2][1] = '8';
        board[2][2] = '9';

        cout << "Name of the first player: " << endl;
        getline(cin, n1);
        cout << "Name of the second player: " << endl;
        getline(cin, n2);

        cout << "\n"
             << endl;
        cout << n1 << " gets symbol 'x' and " << n2 << " gets symbol 'o'" << endl;
        cout << "\n"
             << endl;

        while (!result())
        {
            start();
            choice();
            cout << "\n"
                 << endl;
            result();
        }

        if (sym == 'x' && draw == false)
        {
            start();
            cout << n2 << " WON !!   " << n1 << " LOST !!" << endl;
        }

        else if (sym == 'o' && draw == false)
        {
            start();
            cout << n1 << " WON!!    " << n2 << " LOST !!" << endl;
        }

        else
        {
            start();
            cout << "Match is Drawn" << endl;
        }

        cout << "Do you want to play more ? (y/n):" << endl;
        cin >> ans;
        cin.ignore();
    } while (ans == 'y' || ans == 'Y');

    return 0;
}
#include <iostream>
using namespace std;

char board[3][3];
char player = 'X';

void initializeBoard()
{
    char ch = '1';

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            board[i][j] = ch++;
        }
    }
}

void displayBoard()
{
    cout << "\n";

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cout << " " << board[i][j];

            if(j < 2)
                cout << " |";
        }

        cout << endl;

        if(i < 2)
            cout << "---|---|---" << endl;
    }

    cout << endl;
}

bool makeMove(int pos)
{
    int row = (pos - 1) / 3;
    int col = (pos - 1) % 3;

    if(board[row][col] != 'X' && board[row][col] != 'O')
    {
        board[row][col] = player;
        return true;
    }

    return false;
}

bool checkWin()
{
    for(int i = 0; i < 3; i++)
    {
        if(board[i][0] == player &&
           board[i][1] == player &&
           board[i][2] == player)
            return true;

        if(board[0][i] == player &&
           board[1][i] == player &&
           board[2][i] == player)
            return true;
    }

    if(board[0][0] == player &&
       board[1][1] == player &&
       board[2][2] == player)
        return true;

    if(board[0][2] == player &&
       board[1][1] == player &&
       board[2][0] == player)
        return true;

    return false;
}

bool checkDraw()
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] != 'X' &&
               board[i][j] != 'O')
                return false;
        }
    }

    return true;
}

int main()
{
    char replay;

    do
    {
        initializeBoard();
        player = 'X';

        while(true)
        {
            displayBoard();

            int pos;

            cout << "Player " << player << ", Enter Position (1-9): ";
            cin >> pos;

            if(pos < 1 || pos > 9 || !makeMove(pos))
            {
                cout << "\nInvalid Move!\n";
                continue;
            }

            if(checkWin())
            {
                displayBoard();
                cout << "\nPlayer " << player << " Wins!\n";
                break;
            }

            if(checkDraw())
            {
                displayBoard();
                cout << "\nMatch Draw!\n";
                break;
            }

            if(player == 'X')
                player = 'O';
            else
                player = 'X';
        }

        cout << "\nPlay Again? (Y/N): ";
        cin >> replay;

    } while(replay == 'Y' || replay == 'y');

    cout << "\nThank You for Playing!\n";

    return 0;
}

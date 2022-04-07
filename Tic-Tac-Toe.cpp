/*
 *
 * Filename:    Tic-Tac-Toe.cpp
 * Purpose:     Tic-Tac-Toe
 * Author:      Colton Wilson
 *
 *
 *
 * Created on November 24, 2020, 1:31 PM
*/
//Directives
#include<iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;
//Constants
const int MAX_SIZE = 3;

void display(char board[MAX_SIZE][MAX_SIZE]);
//PreCondition: board has been declared an array.
//PostCondition:N/A
//Purpose: Prints board to screen

bool WinningCheck(char board[MAX_SIZE][MAX_SIZE], char players[], char player);
//PreCondition: board, and players have been declared as arrays. player has been declared.
//PostCondition: bool value returned
//Purpose: Check to see if move wins


//Call main function
int main(void)
{
    //Declare Variables and Arrays
    char board[MAX_SIZE][MAX_SIZE] =
    {
       {'1','2','3'},
       {'4','5','6'},
       {'7','8','9'}
    };
    char players[2] = { 'X','O' };
    int player = 0, turn = 1, n;
    char move;
    bool win;
    //Do while loop to stop if gets to 10 turns
    do {
        //Call display function
        display(board);
        //Print to screen which players turn
        cout << "Player " << players[player] << ", turn: ";
        cin >> move;
        //Do while loop to see if move is valid and replace element with letter
        do {
            for (int i = 0; i < MAX_SIZE; i++)
            {
                for (int j = 0; j < MAX_SIZE; j++)
                {
                    if (move == board[i][j])
                    {
                        board[i][j] = players[player];
                        n = 1;
                        j = MAX_SIZE;
                        i = MAX_SIZE;
                    }
                    else
                    {
                        n = -1;
                    }
                }
            }
            //If not a valid move, prompt user to intput another position
            if (n == -1)
            {
                cout << "Not a valid Position";
                cout << endl;
                cout << " Please enter a valid Position: ";
                cin >> move;
            }
        } while (n == -1);

        //Call WinningCheck function 
        win = WinningCheck(board, players, player);


        //Print win message if game is won
        if (win == true)
        {
            cout << "Winner!";
            cout << endl;
            cout << "Congratulations to Player " << players[player] << "!";
            cout << endl;
            display(board);
            turn = 11;
        }
        //Print loss message if no one wins
        if (turn == 9 && win == false)
        {
            cout << "No one wins";
            cout << endl;
            display(board);
            turn = 11;
        }

        //Update turn count
        turn++;
        //Update to switch players
        player = (player + 1) % 2;

    } while (turn < 10);

    exit(EXIT_SUCCESS);
}
//Function Definition of display
void display(char board[MAX_SIZE][MAX_SIZE])
{
    //For loops to print the elements of the board
    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            cout << board[i][j];
        }
        cout << endl;
    }
}

//Function Definition of WinningCheck
bool WinningCheck(char board[MAX_SIZE][MAX_SIZE], char players[], char player)
{
    //Declarations with function as scope
    int i;
    int j{ 0 };
    //For loop to check each Horizontal element
    for (i = 0; i < MAX_SIZE; i++)
    {
        //If all the same player, game is won
        if (board[i][j] == players[player] && board[i][j + 1] == players[player] && board[i][j + 2] == players[player])
        {
            return true;
        }
    }
    i = 0;
    //For loop to check each Vertical element
    for (j = 0; j < MAX_SIZE; j++)
    {
        if (board[i][j] == players[player] && board[i + 1][j] == players[player] && board[i + 2][j] == players[player])
        {
            //If all the same player, game is won
            return true;
        }
    }
    j = 0;
    //For loop to check each top left to bottom right diagonal element
    if (board[i][j] == players[player] && board[i + 1][j + 1] == players[player] && board[i + 2][j + 2] == players[player])
    {
        //If all the same player, game is won
        return true;
    }
    //For loop to check each bottom left to top right diagonal element
    if (board[i + 2][j] == players[player] && board[i + 1][j + 1] == players[player] && board[i][j + 2] == players[player])
    {
        //If all the same player, game is won
        return true;
    }
    //Else game keeps playing
    return false;
}

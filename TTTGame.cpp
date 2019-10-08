/* Class: TicTacToe
 * Author: Sarah Ruth Nicholls
 * Description: A program that implements the game Tic-Tac-Toe
 */

#include <iostream>
#include "TicTacToe.h"
#include <ctime>
using namespace std;

int main() {
    TicTacToe game;
    int numPlayers;

    cout<<"One-Player or Two-Players( 1 or 2): "<<endl;
    cin>>numPlayers;

        game.initializeBoard();
        game.printBoard();
        int row = 0;
        int col = 0;
        //Boolean needed so placeMark is only run once in the do-while loop
        bool valid;

        //Game for two players
        if(numPlayers==2) {
        while (!game.isBoardFull() && !game.checkForWin()) {

            cout << "Player " << game.getCurrentPlayerNumber() << endl;

            //loop that runs while the guess is not in correct bounds
            do {
                cout << "Enter a row and column (0-2): " << endl;
                cin >> row;
                cin >> col;
                cout << endl;
                valid = game.placeMark(row, col);
                if (!valid) {
                    cout << "Invalid entry. Please enter a new row and column (0-2)" << endl;
                }
            } while (!valid);
            //prints board
            game.printBoard();

            //checks if loop will stop so appropriate message can be displayed.
            if (game.checkForWin()) {
                cout << "Game over! Player " << game.getCurrentPlayerNumber() << " won!" << endl;
            } else if (game.isBoardFull()) {
                cout << "Game over! Reached a draw" << endl;
            }
            game.changePlayer();
        }
    }

    if(numPlayers==1){
        //random to choose starting player and computer's guesses
        srand(time(0));
        int start=(rand()%2+1);
        if(game.getCurrentPlayerNumber()!=start){
            game.changePlayer();
        }

        while (!game.isBoardFull() && !game.checkForWin()) {

            cout << "Player " << game.getCurrentPlayerNumber() << endl;
            if(game.getCurrentPlayerNumber()==2){

                do {//still need do-while loop to check for repeated guesses
                    row=rand()%3;
                    col=rand()%3;
                    cout<<row<<" "<<col<<endl;
                    valid = game.placeMark(row, col);
                } while (!valid);
            }

            //loop that runs while the guess is not in correct bounds
            if(game.getCurrentPlayerNumber()==1) {
                do {
                    cout << "Enter a row and column (0-2): " << endl;
                    cin >> row;
                    cin >> col;
                    cout << endl;
                    valid = game.placeMark(row, col);
                    if (!valid) {
                        cout << "Invalid entry. Please enter a new row and column (0-2)" << endl;
                    }
                } while (!valid);
            }
            //prints board
            game.printBoard();

            //checks if loop will stop so appropriate message can be displayed.
            if (game.checkForWin()) {
                cout << "Game over! Player " << game.getCurrentPlayerNumber() << " won!" << endl;
            } else if (game.isBoardFull()) {
                cout << "Game over! Reached a draw" << endl;
            }
            game.changePlayer();
        }
    }


    return 0;
}
//
// Copyright (c) 2023 by Kenner Hartman. All rights reserved.
// Licensed under the MIT license. See LICENSE.md file in the project root for details.
//

// next to linee necessary for inputting and outputtingl; 
// 'using namespace std' makes it so I do not have to type out 'std::cout' and 'std::cin' for console I/O
#include <iostream>
using namespace std;

// the functions below are called up here so I can keep all of their code and logic below 'int main()'
// but still be able to reference them from 'int main()'

// 'read' and loop through the board and display it, with necessary formatting
void displayBoard(char* board);

// place an X or O, wherever the player chooses it to be
int placeXorO(char* board, char* player, int input);

// check if the board is in a winning gamestate
void checkWin(char* board);

// if counter is less than 9, game continues; goes up every time X or O is successfully placed on the board
int counter = 0;

int main() {
    char board[9] = {   '-', '-', '-', 
                        '-', '-', '-', 
                        '-', '-', '-'
                    };
    
    // store input of player
    int input;
    
    // decide if X or O goes first
    srand(time(NULL));
    int turn = rand() % 2;
    char player[1] = {'\0'};

    // if 'isRunning' is "0", the program continues to run; if "-1", the program exits
    int isRunning = 0;

    cout << "\n";
    displayBoard(board);

    while (isRunning == 0 && counter < 9) {
        if (turn == 0) {
            *player = 'X';

            cout << "X's turn (Enter a number between 1 and 9): ";
            cin >> input;
            cout << "\n";

            turn = 1;
        }
        else {
            *player = 'O';

            cout << "O's turn (Enter a number between 1 and 9): ";
            cin >> input;
            cout << "\n";

            turn = 0;
        }

        // place X or O on the board
        switch(input) {
            case 1:
                turn = placeXorO(board, player, input);
                checkWin(board);
                break;
            case 2:
                turn = placeXorO(board, player, input);
                checkWin(board);
                break;
            case 3:
                turn = placeXorO(board, player, input);
                checkWin(board);
                break;
            case 4:
                turn = placeXorO(board, player, input);
                checkWin(board);
                break;
            case 5:
                turn = placeXorO(board, player, input);
                checkWin(board);
                break;
            case 6:
                turn = placeXorO(board, player, input);
                checkWin(board);
                break;
            case 7:
                turn = placeXorO(board, player, input);
                checkWin(board);
                break;
            case 8:
                turn = placeXorO(board, player, input);
                checkWin(board);
                break;
            case 9:
                turn = placeXorO(board, player, input);
                checkWin(board);
                break;
            default: // if input is not a number between 1 and 9, the player who just took the last turn goes again
                if (*player == 'X') {
                    turn = 0;
                } else if (*player == 'O') {
                    turn = 1;
                }
        }
    }

    return 0;
}

// 'read' and loop through the board and display it, with necessary formatting
void displayBoard(char* board) {
    for (int i = 0; i < 9; i++) {
        // if we are not at the last char of 'board'
        if (i != sizeof(board)) {
            // 'endl' is absent to prevent the "-" from being spaced out when printed to console
            cout << board[i];
        } else {
            // print last char; declare end of line; does not show '%'
            cout << board[i] << "\n\n";
        }
        
        // make a 3x3 square of "-"
        if (i == 2 || i == 5) {
            cout << "\n";
        } 
    }
}

// place an X or O, wherever the player chooses it to be
int placeXorO(char* board, char* player, int input) {
    if (board[input - 1] == '-') {
        board[input - 1] = *player;
        
        counter += 1;

        if (*player == 'X') {
            displayBoard(board);
            return 1;
        } else if (*player == 'O') {
            displayBoard(board);
            return 0;
        }

    } else { // if board[input - 1] is equal to 'O' or 'X', the player that just went gets to go again
        if (*player == 'X') {
            return 0;
        } else if (*player == 'O') {
            return 1;
        }
    }
}

// check if the board is in a winning gamestate
void checkWin(char* board) {
    
    /*

        0, 1, 2
        3, 4, 5
        6, 7, 8

    */

    // X; rows 1-3 win state
    if (board[0] == 'X' && board[1] == 'X' && board[2] == 'X') {
        cout << "X wins the game!" << "\n";
        exit(0);
    }

    if (board[3] == 'X' && board[4] == 'X' && board[5] == 'X') {
        cout << "X wins the game!" << "\n";
        exit(0);
    }

    if (board[6] == 'X' && board[7] == 'X' && board[8] == 'X') {
        cout << "X wins the game!" << "\n";
        exit(0);
    }

    // X; columns 1-3 win state

    if (board[0] == 'X' && board[3] == 'X' && board[6] == 'X') {
        cout << "X wins the game!" << "\n";
        exit(0);
    }

    if (board[1] == 'X' && board[4] == 'X' && board[7] == 'X') {
        cout << "X wins the game!" << "\n";
        exit(0);
    }

    if (board[2] == 'X' && board[5] == 'X' && board[8] == 'X') {
        cout << "X wins the game!" << "\n";
        exit(0);
    }

    // X; diagonal 1-3 win state

    if (board[0] == 'X' && board[4] == 'X' && board[8] == 'X') {
        cout << "X wins the game!" << "\n";
        exit(0);
    }

    if (board[2] == 'X' && board[4] == 'X' && board[6] == 'X') {
        cout << "X wins the game!" << "\n";
        exit(0);
    }

    // O; rows 1-3 win state

    if (board[0] == 'O' && board[1] == 'O' && board[2] == 'O') {
        cout << "O wins the game!" << "\n";
        exit(0);
    }

    if (board[3] == 'O' && board[4] == 'O' && board[5] == 'O') {
        cout << "O wins the game!" << "\n";
        exit(0);
    }

    if (board[6] == 'O' && board[7] == 'O' && board[8] == 'O') {
        cout << "O wins the game!" << "\n";
        exit(0);
    }

    // O; columns 1-3 win state

    if (board[0] == 'O' && board[3] == 'O' && board[6] == 'O') {
        cout << "O wins the game!" << "\n";
        exit(0);
    }

    if (board[1] == 'O' && board[4] == 'O' && board[7] == 'O') {
        cout << "O wins the game!" << "\n";
        exit(0);
    }

    if (board[2] == 'O' && board[5] == 'O' && board[8] == 'O') {
        cout << "O wins the game!" << "\n";
        exit(0);
    }

    // O; diagonal 1-3 win state

    if (board[0] == 'O' && board[4] == 'O' && board[8] == 'O') {
        cout << "O wins the game!" << "\n";
        exit(0);
    }

    if (board[2] == 'O' && board[4] == 'O' && board[6] == 'O') {
        cout << "O wins the game!" << "\n";
        exit(0);
    }

}


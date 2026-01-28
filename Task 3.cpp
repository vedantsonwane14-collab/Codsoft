#include <iostream>

using namespace std;

char board[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

void drawBoard() {
    cout << "--- Tic-Tac-Toe ---";
    cout << " Player 1 (X)  -  Player 2 (O)" <<endl<<endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[1] << "  |  " << board[2] << "  |  " << board[3]<<endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[4] << "  |  " << board[5] << "  |  " << board[6]<<endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[7] << "  |  " << board[8] << "  |  " << board[9]<<endl;
    cout << "     |     |     " << endl << endl;
}

int checkWin() {
    const int winPatterns[8][3] = {
        {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, 
        {1, 4, 7}, {2, 5, 8}, {3, 6, 9}, 
        {1, 5, 9}, {3, 5, 7}             
    };

    for (int i = 0; i < 8; i++) {
        if (board[winPatterns[i][0]] == board[winPatterns[i][1]] && 
            board[winPatterns[i][1]] == board[winPatterns[i][2]]) {
            return 1; 
        }
    }

    bool isDraw = true;
    for (int i = 1; i <= 9; i++) {
        if (board[i] == (char)(i + '0')) { 
            isDraw = false;
            break;
        }
    }
    if (isDraw) return 0;
    return -1;
}

int main() {
    int player = 1, i, choice;
    char mark;

    do {
        drawBoard();
        player = (player % 2) ? 1 : 2;

        cout << "Player " << player << ", enter a number:  ";
        cin >> choice;

        mark = (player == 1) ? 'X' : 'O';

        if (choice >= 1 && choice <= 9 && board[choice] == (char)(choice + '0')) {
            board[choice] = mark;
        } else {
            cout <<"Invalid move! Press Enter to try again.";
            player--; 
            cin.ignore();
            cin.get();
        }

        i = checkWin();
        player++;
    } while (i==-1);

    drawBoard();
    if (i == 1)
        cout<<"==>\aPlayer"<< --player <<"wins!";
    else
        cout<<"==>\aGame draw";

    return 0;
}

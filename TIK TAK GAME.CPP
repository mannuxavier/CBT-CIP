#include <iostream>
#include <vector>
using namespace std;

class TicTacToe {
private:
    vector<vector<char > > board;
    char currentPlayer;

public:
    TicTacToe() {
        board = vector<vector<char> >(3, vector<char>(3, ' ')); // Space added for compatibility
        currentPlayer = 'X'; // X always starts
    }

    void displayBoard() {
        cout << "\n";
        for (int i = 0; i < 3; ++i) {
            cout << " ";
            for (int j = 0; j < 3; ++j) {
                cout << board[i][j];
                if (j < 2) cout << " | ";
            }
            cout << "\n";
            if (i < 2) cout << "---|---|---\n";
        }
        cout << "\n";
    }

    bool makeMove(int row, int col) {
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;
            return true;
        }
        return false;
    }

    bool checkWin() {
        for (int i = 0; i < 3; ++i)
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
                return true;

        for (int i = 0; i < 3; ++i)
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
                return true;

        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
            return true;

        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
            return true;

        return false;
    }

    bool isDraw() {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (board[i][j] == ' ')
                    return false;
        return true;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    void playGame() {
        cout << "Welcome to Tic-Tac-Toe!\n";
        displayBoard();

        while (true) {
            int row, col;
            cout << "Player " << currentPlayer << ", enter your move (row and column: 0-2): ";
            cin >> row >> col;

            if (!makeMove(row, col)) {
                cout << "Invalid move. Try again.\n";
                continue;
            }

            displayBoard();

            if (checkWin()) {
                cout << "?? Player " << currentPlayer << " wins! ??\n";
                break;
            }

            if (isDraw()) {
                cout << "It's a draw! ??\n";
                break;
            }

            switchPlayer();
        }
    }
};

int main() {
    TicTacToe game;
    game.playGame();
    return 0;
}

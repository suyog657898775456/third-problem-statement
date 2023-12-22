#include <iostream>
#include <vector>


void displayBoard(const std::vector<std::vector<char>>& board);
bool isMoveValid(const std::vector<std::vector<char>>& board, int row, int col);
bool checkForWin(const std::vector<std::vector<char>>& board, char player);
bool checkForDraw(const std::vector<std::vector<char>>& board);
void switchPlayer(char& currentPlayer);
bool playAgain();

int main() {
    do {
        // Initialize the game board
        std::vector<std::vector<char>> board(3, std::vector<char>(3, ' '));

        // Players
        char playerX = 'X';
        char playerO = 'O';
        char currentPlayer = playerX;

        // Game loop
        do {
            // Display the current state of the board
            displayBoard(board);

            // Player input
            int row, col;
            do {
                std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
                std::cin >> row >> col;
            } while (!isMoveValid(board, row, col));

            // Update the board with the player's move
            board[row - 1][col - 1] = currentPlayer;

            // Check for win
            if (checkForWin(board, currentPlayer)) {
                displayBoard(board);
                std::cout << "Player " << currentPlayer << " wins!\n";
                break;
            }

            // Check for draw
            if (checkForDraw(board)) {
                displayBoard(board);
                std::cout << "It's a draw!\n";
                break;
            }

            // Switch players for the next turn
            switchPlayer(currentPlayer);

        } while (true);

    } while (playAgain());

    return 0;
}

// Function definitions

void displayBoard(const std::vector<std::vector<char>>& board) {
    std::cout << "Game Board:\n";
    for (const auto& row : board) {
        for (char cell : row) {
            std::cout << cell << ' ';
        }
        std::cout << '\n';
    }
}

bool isMoveValid(const std::vector<std::vector<char>>& board, int row, int col) {
    // Check if the move is within the board boundaries and the cell is empty
    return row >= 1 && row <= 3 && col >= 1 && col <= 3 && board[row - 1][col - 1] == ' ';
}

bool checkForWin(const std::vector<std::vector<char>>& board, char player) {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

bool checkForDraw(const std::vector<std::vector<char>>& board) {
    // Check if all cells are filled
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false; // There is an empty cell, the game is not a draw
            }
        }
    }
    return true; // All cells are filled, the game is a draw
}

void switchPlayer(char& currentPlayer) {
    // Switch between X and O
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

bool playAgain() {
    char choice;
    std::cout << "Do you want to play again? (y/n): ";
    std::cin >> choice;
    getch();
     return (choice == 'y' || choice == 'Y');
}

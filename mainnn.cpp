#include <iostream>

char board[3][3];
char currentPlayer;

// Initialize the board
void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Display the game board
void displayBoard() {
    std::cout << "\n";
    std::cout << "   1   2   3\n";
    for (int i = 0; i < 3; i++) {
        std::cout << i + 1 << "  ";
        for (int j = 0; j < 3; j++) {
            std::cout << board[i][j];
            if (j < 2) std::cout << " | ";
        }
        std::cout << "\n";
        if (i < 2) std::cout << "  ---+---+---\n";
    }
    std::cout << "\n";
}

// Check if the current player has won
bool checkWin() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
            return true;
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
            return true;
    }
    
    // Check diagonals
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
        return true;
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
        return true;
    
    return false;
}

// Check if the board is full (draw)
bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

// Main game function
void playGame() {
    initializeBoard();
    currentPlayer = 'X';
    int row, col;
    bool gameOver = false;
    
    while (!gameOver) {
        displayBoard();
        std::cout << "Player " << currentPlayer << ", enter your move (row column): ";
        std::cin >> row >> col;
        
        // Convert to 0-based index
        row--; col--;
        
        // Validate input
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            std::cout << "Invalid move! Try again.\n";
            continue;
        }
        
        // Place the mark
        board[row][col] = currentPlayer;
        
        // Check for win
        if (checkWin()) {
            displayBoard();
            std::cout << "Player " << currentPlayer << " WINS!\n";
            gameOver = true;
        }
        // Check for draw
        else if (checkDraw()) {
            displayBoard();
            std::cout << "It's a DRAW!\n";
            gameOver = true;
        }
        // Switch player
        else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }
}

int main() {
    char playAgain;
    
    std::cout << "=== TIC-TAC-TOE GAME ===\n";
    
    do {
        playGame();
        
        std::cout << "\nWould you like to play again? (y/n): ";
        std::cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');
    
    std::cout << "\nThanks for playing Tic-Tac-Toe!\n";
    return 0;
}
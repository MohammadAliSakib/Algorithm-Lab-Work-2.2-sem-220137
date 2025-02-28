#include <iostream>
using namespace std;

const int MAX_N = 10; // Maximum board size
int board[MAX_N][MAX_N]; // Chessboard
int result[MAX_N]; // Stores column positions of queens

// Function to check if it is safe to place the queen at board[row][col]
bool isSafe(int row, int col, int n) {
    int i, j;

    // Check this column on upper side
    for (i = 0; i < row; i++) {
        if (board[i][col])
            return false;
    }

    // Check upper diagonal on left side
    for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j])
            return false;
    }

    // Check upper diagonal on right side
    for (i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j])
            return false;
    }

    return true;
}

bool placeQueens(int row, int n) {
    if (row == n) return true;

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col, n)) {
            board[row][col] = 1;
            result[row] = col + 1; // Store the 1-based column index

            if (placeQueens(row + 1, n))
                return true;

            board[row][col] = 0; // Backtrack
        }
    }
    return false;
}

void nQueen(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = 0;
        }
    }

    if (placeQueens(0, n)) {
        for (int i = 0; i < n; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    } else {
        cout << "-1" << endl;
    }
}

int main() {
    int n = 4;
    nQueen(n);
    return 0;
}


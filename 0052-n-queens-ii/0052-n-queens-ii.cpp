class Solution {
public:
    int count = 0;

    bool isSafe(const vector<vector<bool>>& board, int n, int row, int col) {
        // Check column
        for (int tempRow = 0; tempRow < n; ++tempRow) {
            if (tempRow != row && board[tempRow][col]) {
                return false;
            }
        }

        // Check row
        for (int tempCol = 0; tempCol < n; ++tempCol) {
            if (tempCol != col && board[row][tempCol]) {
                return false;
            }
        }

        // Check upper-left diagonal
        int tempRow = row - 1;
        int tempCol = col - 1;
        while (tempRow >= 0 && tempCol >= 0) {
            if (board[tempRow][tempCol]) {
                return false;
            }
            tempRow--;
            tempCol--;
        }

        // Check lower-right diagonal
        tempRow = row + 1;
        tempCol = col + 1;
        while (tempRow < n && tempCol < n) {
            if (board[tempRow][tempCol]) {
                return false;
            }
            tempRow++;
            tempCol++;
        }

        // Check upper-right diagonal
        tempRow = row - 1;
        tempCol = col + 1;
        while (tempRow >= 0 && tempCol < n) {
            if (board[tempRow][tempCol]) {
                return false;
            }
            tempRow--;
            tempCol++;
        }

        // Check lower-left diagonal
        tempRow = row + 1;
        tempCol = col - 1;
        while (tempRow < n && tempCol >= 0) {
            if (board[tempRow][tempCol]) {
                return false;
            }
            tempRow++;
            tempCol--;
        }

        return true;
    }

    void solveNQueensUtil(vector<vector<bool>>& board, int n, int row) {
        if (row == n) {
            count++;
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (isSafe(board, n, row, col)) {
                board[row][col] = true;
                solveNQueensUtil(board, n, row + 1);
                board[row][col] = false;
            }
        }
    }

    int totalNQueens(int n) {
        count = 0;
        vector<vector<bool>> board(n, vector<bool>(n, false));
        solveNQueensUtil(board, n, 0);
        return count;
    }
};

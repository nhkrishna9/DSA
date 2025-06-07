class Solution {
public:
    vector<vector<string>> solutions;

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

    void solve(vector<vector<bool>>& board, int n, int row) {
        if (row == n) {
            // Convert the bool board to a string board
            vector<string> currentSolution;
            for (int i = 0; i < n; ++i) {
                string rowStr;
                for (int j = 0; j < n; ++j) {
                    rowStr += (board[i][j] ? 'Q' : '.');
                }
                currentSolution.push_back(rowStr);
            }
            solutions.push_back(currentSolution);
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (isSafe(board, n, row, col)) {
                board[row][col] = true;
                solve(board, n, row + 1);
                board[row][col] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        solutions.clear();
        vector<vector<bool>> board(n, vector<bool>(n, false));
        solve(board, n, 0);
        return solutions;
    }
};

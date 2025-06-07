class Solution {
public:
    int count = 0;

    bool isValid(const vector<vector<bool>>& board, int n, int row, int col){
        // Row and column checks
        for(int i = 0; i < n; i++){
            if(i != row && board[i][col]) return false;
            if(i != col && board[row][i]) return false;
        }

        // Diagonal checks
        // Top-left to bottom-right
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
            if(board[i][j]) return false;

        for(int i = row + 1, j = col + 1; i < n && j < n; i++, j++)
            if(board[i][j]) return false;

        // Top-right to bottom-left
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
            if(board[i][j]) return false;

        for(int i = row + 1, j = col - 1; i < n && j >= 0; i++, j--)
            if(board[i][j]) return false;

        return true;
    }

    void Func(vector<vector<bool>>& board, int n, int row){
        if(row == n){
            count++;
            return;
        }

        for(int col = 0; col < n; col++){
            if(isValid(board, n, row, col)){
                board[row][col] = true;
                Func(board, n, row + 1);
                board[row][col] = false;
            }
        }
    }

    int totalNQueens(int n) {
        vector<vector<bool>> board(n, vector<bool>(n, false));
        count = 0;
        Func(board, n, 0);
        return count;
    }
};

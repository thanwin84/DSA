class Solution {
    bool isSafe(int row, int col,vector<string>&board){
        int n = board.size();
        int currRow = row;
        int currCol = col;
        while (currRow >= 0 && currCol >= 0){
            if (board[currRow][currCol] == 'Q'){
                return false;
            }
            currRow--;
            currCol--;
        }
        currRow = row;
        currCol = col;
        while (currCol >= 0){
            if (board[row][currCol] == 'Q'){
                return false;
            }
            currCol--;
        }
        currRow = row;
        currCol = col;
        while (currRow < n && currCol >= 0){
            if (board[currRow][currCol] == 'Q'){
                return false;
            }
            currRow++;
            currCol--;
        }
        return true;
    }
    void solve(int col,vector<string>&board, vector<vector<string>> &ans, int n){
        if (col == n){
            ans.push_back(board);
            return;
        }
        for (int currentRow = 0; currentRow < n; currentRow++){
            if (isSafe(currentRow, col, board)){
                board[currentRow][col] = 'Q';
                solve(col + 1, board, ans, n);
                board[currentRow][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        solve( 0, board, ans, n);
        return ans;
    }
};

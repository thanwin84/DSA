// brute force
class Solution {
    void markRow(vector<vector<int>>& matrix, int row){
        for (int i = 0; i < matrix[0].size(); i++){
            if (matrix[row][i] != 0){
                matrix[row][i] = -1;
            }
        }
    }
    void markColumn(vector<vector<int>>& matrix, int col){
        for (int i = 0; i < matrix.size(); i++){
            if (matrix[i][col] != 0){
                matrix[i][col] = -1;
            }
        }
    }
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                if (matrix[i][j] == 0){
                    markRow(matrix, i);
                    markColumn(matrix, j);
                }
            }
        }
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                if (matrix[i][j] == -1){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

// tc: O(n * m) * O(n + m) + O(n * m)

// better approach
/*
first we will check which column and rows needs to marked as 0

*/
class Solution { 
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size(); 
        int cols = matrix[0].size();
        vector<int> rowsVisited(rows, 0); // tract which row needs to be marked as 0
        vector<int> colsVisited(cols, 0); // tract which column nees to be marked as 0
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                if (matrix[i][j] == 0){
                    rowsVisited[i] = 1;
                    colsVisited[j] = 1;
                }
            }
        }
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                if (rowsVisited[i] == 1 || colsVisited[j] == 1){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
// time: O(n * m) and space: O(n + m)
/*
Can you optimize this code further?
we are already solving this problem in O(n * m). in order to treverse the matrix the time complexity will be at least O(n *m)
so we can not optimize time complexity here
But we can optimize space 
Use the first row and first column of the matrix to store information:
Treat the first row and first column as flags to indicate whether the corresponding row or column should be set to zero.
Use two additional variables to track whether the first row and first column should be zeroed out entirely (since we are using the first row and column for marking).
Steps:

Traverse the matrix to check for zero elements.
If a matrix element at position (i, j) is zero, mark the first row and first column at positions i and j to indicate the row and column should be zeroed.
Traverse the matrix again, skipping the first row and column, and use the first row and first column to set the corresponding elements to zero.
Finally, set the first row and first column to zero if needed.
*/
class Solution { 
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        bool firstRowZero = false, firstColZero = false;
        // check if first row needs to be marked as zero
        for (int i = 0; i < cols; i++){
            if (matrix[0][i] == 0){
                firstRowZero = true;
                break;
            }
        }
        // check if the first column needs to be marked as 0
        for (int i = 0; i < rows; i++){
            if (matrix[i][0] == 0){
                firstColZero = true;
                break;
            }
        }
        for (int i = 1; i < rows; i++){
            for (int j = 1; j < cols; j++){
                if (matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < rows; i++){
            for (int j = 1; j < cols; j++){
                if (matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        if (firstRowZero){
            for (int i = 0; i < cols; i++){
                matrix[0][i] = 0;
            }
        }
        if (firstColZero){
            for (int i = 0; i < rows; i++){
                matrix[i][0] = 0;
            }
        }
    }
};
// time: O(n *m) and space: O(1)

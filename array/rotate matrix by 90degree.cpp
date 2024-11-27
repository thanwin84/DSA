// brute force using space

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include<set>
#include <unordered_set>
#include <ctime>
#include <cctype>
#include <map>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> output(n, vector<int>(n, 0));
        int col = n - 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                output[j][col] = matrix[i][j];
            }
            col--;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << output[i][j] << " ";
            }
            cout << endl;
        }
    }
};
int main()
{
    
    vector<vector<int>> mat = { {1, 2, 3},{4, 5, 6},{7, 8, 9} };
    Solution obj;
    obj.rotate(mat);

    return 0;
}
/*
In terms of time complexity, this can't be optimized further. Cause we must touch to each element in matrix which is O(n*n)
But we can optimize space 
By observation, we see that the first column of the original matrix is the reverse of the first row of the rotated matrix, 
so that’s why we transpose the matrix and then reverse each row, and since we are making changes in the matrix itself space complexity gets reduced to O(1).
*/
class Solution {
    void swap(vector<vector<int>>& matrix, int i, int j){
        int temp = matrix[i][j];
        matrix[i][j] = matrix[j][i];
        matrix[j][i] = temp;
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // tranpose the matrix: change column to row
        for (int i = 0; i < n - 1; i++){
            for (int j = i + 1; j < n; j++){
                swap(matrix, j, i);
            }
        }
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cout << matrix[i][j] << " ";
            }
        }
        // reverse each row
        for (int i = 0; i <n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
// time: O(n^2) and space: O(1)

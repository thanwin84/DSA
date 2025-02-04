vector<vector<int>> arr= { {1, 0}, {0, -1}, {0, 1}, {-1, 0} };
class Solution {
    void solve(int row, int col, vector<vector<int>>& mat, vector<string>&ans, vector<vector<int>> &visited, string temp) {
        int n = mat.size();
        if (row == n - 1 && col == n - 1) {
            ans.push_back(temp);
            return;
        }
        string ways = "DLRU";
        for (int i = 0; i < 4; i++) {
            int nextRow = row + arr[i][0];
            int nextCol = col + arr[i][1];
            if (nextRow >= 0 && nextRow < n && nextCol >= 0 && nextCol < n && !visited[nextRow][nextCol] && mat[nextRow][nextCol] == 1) {
                
                visited[row][col] = 1;
                solve(nextRow, nextCol, mat, ans, visited, temp + ways[i]);
                visited[row][col] = 0;
            }
        }
    }
public:
    vector<string> findPath(vector<vector<int>>& mat) {
        // code here
        vector<string> ans;
        if (mat[0][0] == 0){
            return ans;
        }
        int n = mat.size();
        vector<vector<int>> visited(n, vector<int>(n, 0));
        solve(0, 0, mat, ans,visited, "");
        return ans;
    }
};

// Time Complexity: O(4^(m*n)), because on every cell we need to try 4 different directions.

// Space Complexity:  O(m*n), Maximum Depth of the recursion tree(auxiliary space).

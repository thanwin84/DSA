class Solution {
    void solve(int ind, int currSum, int k, int targetSum,vector<int>&temp, vector<vector<int>> &ans){
        
        if (currSum == targetSum && temp.size() == k){
            ans.push_back(temp);
            return;
        }
        if (ind == 10){
            return;
        }
        temp.push_back(ind);
        solve(ind + 1, currSum + ind,k, targetSum, temp, ans);
        temp.pop_back();
        solve(ind + 1, currSum, k, targetSum, temp, ans);

    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(1, 0, k, n, temp, ans);
        return ans;
    }
};

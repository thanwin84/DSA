class Solution {
    void solve(vector<int>& candidates, vector<vector<int>>& output, vector<int>&temp, int target, int curr){
        if (curr == candidates.size()){
            if (target == 0){
                output.push_back(temp);
                return;
            }
            return;
        }
        
        if (candidates[curr] <= target){
            temp.push_back(candidates[curr]);
            solve(candidates, output, temp, target - candidates[curr], curr);
            temp.pop_back();
        }
        solve(candidates, output, temp, target, curr + 1);

    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> output;
        vector<int> temp;
        solve(candidates, output, temp,  target, 0);
        return output;
    }
};
// time: O(2^n * k) k is for pushing temp array into ans 
// space: O(k * x) if k is the lenght of temp and x is the number of combination

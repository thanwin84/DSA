// naive approache
// naive approach is like combination I problem. But here we have to use set to avoid getting duplicates result.This adds extra time complexity
// optimized approach

class Solution {
    void solve(vector<int>& candidates, int target, int ind, vector<int> &temp,vector<vector<int>>&ans ){
        if (target == 0){
            ans.push_back(temp);
            return;
        }
        for (int currentInd = ind;  currentInd< candidates.size(); currentInd++){
            if (currentInd > ind && candidates[currentInd] == candidates[currentInd -1]){
                continue;
            }
            if (candidates[currentInd] > target){
                break;
            }
            temp.push_back(candidates[currentInd]);
            solve(candidates, target - candidates[currentInd], currentInd + 1, temp, ans);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates, target, 0, temp, ans);
        return ans;
    }
};

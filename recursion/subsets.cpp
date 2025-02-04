class Solution {
    void solve(vector<int>& nums, vector<vector<int>>&ans, vector<int> &temp, int ind){
        if (ind == nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[ind]);
        solve(nums, ans, temp, ind + 1);
        temp.pop_back();
        solve(nums, ans, temp, ind + 1);

    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(nums, ans, temp, 0);
        return ans;
    }
};

// time: O(2^n)

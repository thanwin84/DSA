class Solution {
    void swap(vector<int>& nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    void solve(vector<int>& nums, int start, vector<vector<int>> &ans){
        if (start == nums.size() - 1){
            ans.push_back(nums);
            return;
        }
        for (int ind = start ind < nums.size(); ind++){
            swap(nums, start, ind);
            solve(nums, start + 1, ans);
            swap(nums, start, ind);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(nums, 0, ans);
        return ans;
    }
};

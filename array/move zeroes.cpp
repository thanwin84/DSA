// naive approach
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> result(nums.size(), 0);
        int i = 0;
        
        for (int ind = 0; ind < nums.size();ind++){
            if (nums[ind] != 0){
                nums[i++] = nums[ind];
            }
        }
        for (int ind = i; ind < nums.size();ind++){
            nums[i++] = 0;
        }
        
    }
};
// tc: O(2n)
class Solution {
public:
    void swap(vector<int> &nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    void moveZeroes(vector<int>& nums) {
        vector<int> result(nums.size(), 0);
        int j = -1;
        for (int ind = 0; ind < nums.size(); ind++){
            if (nums[ind] == 0){
                j = ind;
                break;
            }
        }
        if (j != -1){
            for (int ind = j + 1; ind < nums.size(); ind++){
            if (nums[ind] != 0){
                swap(nums, ind, j);
                j++;
            }
        }
        }
    }
};
// tc: O(n) we are doing only n operations here

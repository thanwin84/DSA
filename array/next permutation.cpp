// brute force
// bruce method will be by generating the all posible permuation using recursion, it will take O(n!) time which is a lot

// better solution is from  observation
class Solution {
    void swap(vector<int>&nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int breakPoint = -1;
        for (int i = n - 2; i >= 0; i--){
            if (nums[i] < nums[i + 1]){
                breakPoint = i;
                break;
            }
        }
        if (breakPoint == -1){
            reverse(nums.begin(), nums.end());
        }else {
            // find the next greater than nums[breakPoint]
            for (int i = n - 1; i > breakPoint; i--){
                if (nums[i] > nums[breakPoint]){
                    swap(nums, i, breakPoint);
                    break;
                }
            }
            // now reverse
            reverse(nums.begin() + breakPoint + 1, nums.end());
        }
    }
};
// time: O(3N)

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxValue = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == 1) {
                count++;
                maxValue = max(count, maxValue);
            }
            else if (nums[i] == 0){
                count = 0;
            }
        }
        return maxValue;
    }
};
// tc: O(n) and space: O(1)

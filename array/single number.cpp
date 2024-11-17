// brute force approach
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for (int i = 0; i < nums.size();i++){
            int count = 0;
            for (int j = 0; j < nums.size(); j++){
                if (nums[j] == nums[i]){
                    count++;
                }
            }
            if (count == 1){
                return nums[i];
            }
        }
        return -1;
    }
};
// tc: O(n^2)

//using xor
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int missing = 0;
        for (int &num: nums){
            missing = missing ^ num;
        }
        return missing;
    }
};

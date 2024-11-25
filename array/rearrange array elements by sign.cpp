// brute force
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positives;
        vector<int> negatives;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] < 0) negatives.push_back(nums[i]);
            else {
                positives.push_back(nums[i]);
            }
        }
        for (int i = 0; i < nums.size()/ 2; i++){
            nums[i * 2] = positives[i];
            nums[(i * 2) + 1] = negatives[i];
        }
        return nums;
    }
};
// time: O(n + n/2) and space: O(N)

// optimal approach - single pass
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> result(nums.size(), 0);
        int positiveIndex = 0, negativeIndex = 1;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] >= 0){
                result[positiveIndex] = nums[i];
                positiveIndex = positiveIndex + 2;
            } else {
                result[negativeIndex] = nums[i];
                negativeIndex = negativeIndex + 2;
            }
        }
        
        return result;
    }
};
// time: O(n) and space: O(n)

// follow up: what if the number of negatives and positives are not same.
// we have solve again using brute force
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> result(nums.size(), 0);
        vector<int> positives;
        vector<int> negatives;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= 0) {
                positives.push_back(nums[i]);
            }
            else {
                negatives.push_back(nums[i]);
            }
        }
        int positiveLen = positives.size(), negativeLen = negatives.size();
        if (positiveLen > negativeLen) {
            for (int i = 0; i < negativeLen; i++) {
                result[i * 2] = positives[i];
                result[(i * 2) + 1] = negatives[i];
            }
            int startIndex = negativeLen * 2;
            for (int i = negativeLen; i < positiveLen; i++) {
                result[startIndex++] = positives[i];
            }
        }
        else {
            for (int i = 0; i < positiveLen; i++) {
                result[i * 2] = positives[i];
                result[(i * 2) + 1] = negatives[i];
            }
            int startIndex = positiveLen * 2;
            for (int i = positiveLen; i < negativeLen; i++) {
                result[startIndex++] = negatives[i];
            }
            
        }

        return result;
    }
};
// time: O(2n)

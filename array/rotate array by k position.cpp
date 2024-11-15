// using extra space 
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        vector<int> tempArray;
        for (int i = nums.size() - k; i < nums.size(); i++) {
            tempArray.push_back(nums[i]);
        }
        for (int i = nums.size() - 1; i >= k; i--) {
            nums[i] = nums[i - k];
        }
        for (int i = 0; i < k; i++) {
            nums[i] = tempArray[i];
        }
    }

};
// tc: O(n) and space: O(n)
// O(d) + O(n - d) + O(d) => O(n + d)
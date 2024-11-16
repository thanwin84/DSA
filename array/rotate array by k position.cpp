// using extra space 
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        vector<int> tempArray;
        // keep the left part(array which needs to shifted to the right) array in the temp
        for (int i = nums.size() - k; i < nums.size(); i++) {
            tempArray.push_back(nums[i]);
        }
        // shift all elements starting from 0 from nums.size() -k to the right at i-k distance place
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
//Step 1: Reverse the last k elements of the array

// Step 2: Reverse the first n-k elements of the array.

// Step 3: Reverse the whole array.
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        int n = nums.size();
        reverse(nums.begin() + (n - k), nums.end());
        reverse(nums.begin(), nums.begin() + (n - k));
        reverse(nums.begin(), nums.end()); 
    }
};
// O(d) + o(n - d) + o(n) = O(2n)

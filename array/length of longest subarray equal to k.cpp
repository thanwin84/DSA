// brute force
class Solution {
public:
    int lenOfLongestSubarr(vector<int>& arr, int k) {
        // code here
        int _max = 0;
        for (int i = 0; i < arr.size(); i++) {
            int tempSum = 0;
            for (int j = i; j < arr.size(); j++) {
                tempSum += arr[j];
                if (tempSum == k) {
                    _max = max(j - i + 1, _max);
                    break;
                }
                else if (tempSum > k) {
                    break;
                }
            }
        }
        return _max;
    }
};
// tc: O(n^2) and space: O(1)
// better
class Solution {
public:
    int lenOfLongestSubarr(vector<int>& arr, int k) {
        // code here
        int _max = 0;
        unordered_map<int, int> prefixSum;
        int sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            if (sum == k) {
                _max = max(_max, i + 1);
            }
            int remainingSum = sum - k;
            if (prefixSum.count(remainingSum) != 0) {
                int len = i - prefixSum[remainingSum];
                _max = max(_max, len);
            }
            // added extra condition for handling subarray having 0
            if (prefixSum.count(sum) == 0) {
                prefixSum[sum] = i;
            }
        }
        return _max;
    }
};
// explain what happen when we have 0 and negive numbers in the array.
// tc: O(n) and space: O(n)

// sliding window will not work here because of having negative numbers

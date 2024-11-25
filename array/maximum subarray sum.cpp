// kadane's algorithm
// keep adding element to the current sum
// if current sum becomes less than 0, then discard the current subarray to start a new subarray, cause negetive number will not contribute in larger sum
// before reseting current sum to 0, check if the currentSum is greater than maxSum. cause the current element can also be maxSum
// by doing this we will get max sum.
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int currentSum = 0;
        for (int i = 0; i < nums.size(); i++){
            currentSum += nums[i];
            // if current sum is larger than maxSum, update maxSum
            if (currentSum > maxSum ) maxSum = currentSum;
            // if currentSum becomes less than 0, we can discard the current subarray and start new
            // negetive will never contribute to larger sum
            if (currentSum < 0){
                currentSum = 0;
            }
            
            
        }
        return maxSum;
    }
};

// tc: O(n) and space: O(1)

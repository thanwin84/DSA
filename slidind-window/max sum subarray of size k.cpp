class Solution {
  public:
    int maximumSumSubarray(vector<int>& nums, int k) {
        // code here
        int i = 0;
        int j = k;
        int _max = 0;
        int currentSum = 0;
        for (int i = 0; i < k; i++){
            currentSum += nums[i];
            
        }
        _max = currentSum;
        while (j < nums.size()){
            currentSum += nums[j];
            currentSum -= nums[i];
            _max = max(_max, currentSum);
            i++;
            j++;
        }
        return _max;
    }
};

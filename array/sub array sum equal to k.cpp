class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int currentSum = 0;
        int count = 0;
        unordered_map<int, int> hashmap;
        for (int i = 0; i < nums.size(); i++){
            currentSum += nums[i];
            int remainingSum = currentSum  - k;
            count+= hashmap[remainingSum];
            
            hashmap[currentSum] += 1;

            if (currentSum == k){
                count += 1;
            }
        }
        return count;
    }
};

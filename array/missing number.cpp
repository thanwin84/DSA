class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        for (int i = 1; i <= nums.size(); i++){
            bool flag = false;
            for (auto num: nums){
                if (i == num){
                    flag = true;
                    break;
                }
            }
            if (!flag) return i;
        }
        return 0;
    }
};
// tc: O(n^2) and space: O(1)

// using array hash
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> hash(n + 1, -1);
        for (auto &num: nums){
            hash[num] = 1;
        }
        int missing = 0;
        for (int i = 0; i <= n; i++){
            if (hash[i] == -1){
                missing = i;
                break;
            }
        }
        return missing;
    }
};
// tc:  O(2n) and space: O(n)

// optimal approach
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (auto &num: nums){
            sum += num;
        }
        return (n * (n + 1)) / 2 - sum;
    }
};
// time: O(n) and space: O(1)

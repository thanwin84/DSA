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

// using xor
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xor1 = 0;
        int xor2 = 0;
        for (int i = 0; i < nums.size(); i++){
            xor1 = xor1 ^ nums[i];
            xor2 = xor2 ^ (i + 1);
        }
        return xor1 ^ xor2;
    }
};
//tc: O(n) and space: O(1)
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
// here if the value of n is 10^5, then doing multiplication with n * n will give us int overflow. then we have use long long

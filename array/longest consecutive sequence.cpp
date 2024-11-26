// brute force approach
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()){
            return 0;
        }
        sort(nums.begin(), nums.end());
        int maxLen = 1;
        int count = 1;
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] == nums[i - 1] + 1){
                    count++;
                    maxLen = max(count, maxLen);
            }
            else if (nums[i] == nums[i - 1]){
                continue;
            }
            else {
                count = 1;
            }
        }
        return maxLen;
    }
};
// time: O(nlong)

/*
-----optimal approach-----------
step 1: insert all the elements into hashmap
step 2: treverse the hashmap
step 3: while treversing the hashmap, check if the current element is the starting point of sequence
we can check if the current element is the starting point of sequence just by checking if currentElement-1 exists int the hashmap
step 4: if the current element is starting point of sequence, keep extending the sequence by adding 1 to the current element. while exteding the sequence by 1 each time, we will aso check if it exists in the hashmap and udate the count.
while doing loop, if currentElement+1 doesn't exist in the hashmap, we will break the loop and start a new sequence by reseting the count to 1
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()){
            return 0;
        }
        unordered_map<int, int> hash;
        int count = 1;
        int maxLen = 1;
        for (int i = 0; i < nums.size(); i++){
            hash[nums[i]] = 1;
        }
        for (auto it = hash.begin(); it != hash.end(); it++){
            
            if (hash.count(it->first - 1) > 0){
                continue;
            }
            else {
                int value = it->first;
                while (hash.count(value + 1) > 0){
                    count++;
                    value++;
                }
                maxLen = max(maxLen, count);
                count = 1;
            }
        }
        
        return maxLen;
    }
};
/*
time: O(n) and space: O(n)
*/

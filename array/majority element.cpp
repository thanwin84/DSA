// brute force
// each time we will pick  one element and scan the whole array to count the its occurances. we have to do this for every element.
// we need two loops here,  so time complexity will be O(n^2) and space: O(1)

// using hash map
// we will run a single iteration, while iterating the array we will insert the element into hash. 
// if we use map, the time complexity will be O(nlogn)
// if we use unordered map, the time complexity will be for best and average case o(n). Cause in unordered map, 
// hash operations are O(1) but in the worst it could be O(n). which rarely happens with good hashing function.

// optimal
// step 1: apply more's voting algorithn
// step 2: verify if the element is majority or not
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majorityElement = nums[0];
        int count = 0;
        for (auto &num: nums){
            if (count == 0){
                count++;
                majorityElement = num;
            }
            else if (num != majorityElement){
                count--;
            }
            else {
                count++;
            }
        }
        count = 0;
        for (int num: nums){
            if (num == majorityElement){
                count++;
            }
        }
        if (count > (nums.size() / 2)){
            return majorityElement;
        }
        return majorityElement;
    }
};

// time: O(2n) and space: O(1)

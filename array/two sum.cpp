// brute force
// each time pick one element and compare it with others element- we need two loops here, one for picking up an element and another for comparing it with other elements.
// tc will be O(n^2)

// better approach
// 1. traverse the array.
//2. while traversing subtract (target sum - present element), check if the result of subtraction exists in the hash map, if it exist, that means we got a matching pair
// 3. at the end, insert (present element, current index) to hash map
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++){
            int remainingSum = target - nums[i];
            if (hash.count(remainingSum) > 0){
                result.push_back(hash[remainingSum]);
                result.push_back(i);
                break;
            }
            hash[nums[i]] = i;
        }
        return result;
    }
};
// time complexity: O(n) and space: O(n)



class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s;
        for (auto& num : nums) {
            s.insert(num);
        }
        int i = 0;
        int k = s.size();
        for (int num : s) {
            nums[i++] = num;
        }
        return k;
    }
};

// tc: O(nlogn) + O(n) and space O(n)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int current = 1;
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] != nums[current -1]){
                nums[current] = nums[i];
                current++;
            }
        }
        return current;
    }
};

// tc: O(n) and space: O(1)

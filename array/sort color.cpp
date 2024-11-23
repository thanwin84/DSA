// brute force
// we can use sort built it function to sort the array.

// better solution
// Since the array will contain only 0, 1 , 2. we can take three variable. 
// first = count the number of 0
// second = count the number of 1
// third = count the number of 2
// then we manually update the array in place
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count0 = 0, count1 = 0, count2 = 0;
        for (int i = 0; i < nums.size();i++){
            if (nums[i] == 0) count0++;
            if (nums[i] == 1) count1++;
            if (nums[i] == 2) count2++;
        }
        for (int i = 0; i < count0; i++){
            nums[i] = 0;
        }
        for (int i = count0; i < count0 + count1; i++){
            nums[i] = 1;
        }
        for (int i = count0 + count1; i < nums.size(); i++){
            nums[i] = 2;
        }
    }
};

// time: O(2n) and space: O(1)

// optimal approach -using dutch national algorithm
// check take you forward website to see explanation
class Solution {
public:
    void swap(vector<int> &nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    void sortColors(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int mid = 0;
        while (mid <= high){
        if (nums[mid] == 0) {
            swap(nums, low, mid);
            low++;
            mid++;
        }
        else if (nums[mid] == 1){
            mid++;
        }
        else {
            swap(nums, mid, high);
            high--;
        }
    }
    }
    
};
// time: O(n)

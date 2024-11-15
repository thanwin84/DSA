#include <bits/stdc++.h> 
vector<int> rotateArray(vector<int>& nums, int n) {
    // Write your code here.
    int firstElement = nums[0];
    for (int i = 0; i < nums.size() - 1; i++) {
        nums[i] = nums[i + 1];
    }
    nums[nums.size() - 1] = firstElement;
    return  nums;
}

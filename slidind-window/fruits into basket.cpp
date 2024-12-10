
// Longest sub array that contains at max 2 unique element
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> lookup;
        int i = 0, j = 0;
        int ans = 0;
        int unique_fruits = 0;
        while (j < fruits.size()){
            int fruit = fruits[j];
            lookup[fruit] += 1;
            if (lookup[fruit] == 1){
                unique_fruits++;
            }
            if (unique_fruits <= 2){
                ans = max(ans, j - i + 1);
                j++;
            } else {
                while(unique_fruits > 2 && i <= j){
                    lookup[fruits[i]] -= 1;
                    if (lookup[fruits[i]] == 0){
                        unique_fruits--;
                    }
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};

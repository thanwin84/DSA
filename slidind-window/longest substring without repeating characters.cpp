class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int i = 0;
        int j = 0;
        unordered_map<char, int> lookup;
        while (j < s.size()){
            lookup[s[j]] += 1;
            if (lookup.size() < j - i + 1){
                while (!lookup.empty() && lookup.size() < j - i + 1){
                    lookup[s[i]] -= 1;
                    if (lookup[s[i]] == 0){
                        lookup.erase(s[i]);
                    }
                    i++;
                }
            } else {
                ans = max(ans, j - i + 1);
            }
            j++;
        }
        return ans;
    }
};

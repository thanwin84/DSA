class Solution {
public:
    int longestKSubstr(string& s, int k) {
        int ans = -1;
        unordered_map<char, int> lookup;
        int i = 0;
        int j = 0;
        int unique_chars = 0;
        while (j < s.size()) {
            lookup[s[j]] += 1;
            if (lookup[s[j]] == 1){
                unique_chars++;
            }
            if (unique_chars < k) {
                j++;
            }
            else if (unique_chars == k) {
                ans = max(ans, j - i + 1);
                j++;
            }
            else {
                while (unique_chars > k) {
                    lookup[s[i]] -= 1;
                    if (lookup[s[i]] == 0) {
                        unique_chars--;
                    }
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        unordered_map<char, int> hashmap;
        for (int i = 0; i < p.size();i++){
            if (hashmap[p[i]] > 0){
                hashmap[p[i]] += 1;
            } else {
                hashmap[p[i]] = 1;
            }
        }
        int count = hashmap.size();
        int windowSize = p.size();
        int i = 0;
        int j = 0;
        while (j < s.size()){
            if (hashmap.count(s[j]) > 0){
                hashmap[s[j]] -= 1;
                if (hashmap[s[j]] == 0) count -= 1;
            }
            if (j - i + 1 < windowSize){
                j++;
            } else  {
                if (count == 0){
                    ans.push_back(i);
                }
                // before sliding the window
                if (hashmap.count(s[i]) > 0){
                    hashmap[s[i]] += 1;
                    if (hashmap[s[i]] == 1){
                        count += 1;
                    }
                }
                // slide the window
                i++;
                j++;

            }
        }
        return ans;
    }
};

//  time: O(n) and space: O(m) where m is the size of p

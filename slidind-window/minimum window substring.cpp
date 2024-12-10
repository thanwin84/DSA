class Solution {
public:
    string minWindow(string s, string t) {
        int start = 0;
        int end = 0;
        int i = 0;
        int j = 0;
        int _min = INT_MAX;
        unordered_map<char, int> t_lookup;
        for (int i = 0; i < t.size(); i++){
            t_lookup[t[i]] += 1;
        }
        int count = t_lookup.size();
        while (j < s.size()){
            if (t_lookup.count(s[j])> 0){
                t_lookup[s[j]] -= 1;
                if (t_lookup[s[j]] == 0){
                    count--;
                }
            }
            if (count == 0){
                // find better ans by shrinking the window size
                while (count == 0 && i <= j){
                    if (t_lookup.count(s[i])){
                        t_lookup[s[i]] += 1;
                        if (j - i + 1 < _min){
                            start = i;
                            end = j - i + 1;
                            _min = j - i + 1;
                        }
                        if (t_lookup[s[i]] == 1){
                            count++;
                        }
                    }
                    i++;
                }
            }
            j++;
        }
        return s.substr(start, end);
    }
};

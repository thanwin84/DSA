class Solution {
    bool isPalindrone(string &s, int start, int end){
        while(start <= end){
            if (s[start] != s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void solve(string &s, int start, vector<string> &temp, vector<vector<string>>&ans){
        if (start == s.size()){
            ans.push_back(temp);
            return;
        }
        for (int end = start; end < s.size(); end++){
            if (isPalindrone(s, start, end)){
                temp.push_back(s.substr(start, end - start + 1));
                solve(s, end + 1, temp, ans);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(s, 0, temp, ans);
        return ans;
    }
};

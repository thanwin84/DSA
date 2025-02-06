class Solution {
    bool solve(string &s, unordered_map<string, int> &wordDict,vector<int> &dp, int start){
        
        if (start == s.size()){
            dp[start] = true;
            return true;
        }
        if (dp[start] != -1){
            return dp[start];
        }
        for (int end = start; end < s.size(); end++){
            if (wordDict.count(s.substr(start, end - start + 1)) > 0){
                if (solve(s, wordDict, dp, end + 1)){
                    return true;
                }
            }
        }
        dp[start] = false;
        return  false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, int> wordsMap;
        for (auto &it: wordDict){
            wordsMap[it] = 1;
        }
        vector<int> dp(s.size() + 1, -1);
        return solve(s, wordsMap,dp, 0);
        
    }
};

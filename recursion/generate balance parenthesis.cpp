class Solution {
    bool isValidParenthesis(string& str) {
        vector<char> stack;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '(') {
                stack.push_back(str[i]);
            }
            else {

                if (stack.size() > 0 && stack.back() == '(' && str[i] == ')') {
                    stack.pop_back();
                }
                else {
                    return false;
                }
            }
        }
        if (stack.size() > 0) {
            return false;
        }
        return true;
    }
    void solve(string str, int n, vector<string>& ans) {
        if (str.size() == n * 2) {
            if (isValidParenthesis(str)) {
                ans.push_back(str);
                cout << str << endl;
            }
            return;
        }
        solve(str + '(', n, ans);
        solve(str + ')', n, ans);
    }
public:
    vector<string> generateParenthesis(int n) {
        string temp;
        vector<string> ans;
        solve(temp, n, ans);
        return ans;
    }
};
// time: O(2^n)

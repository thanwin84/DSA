
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include<set>
#include <unordered_set>
#include <ctime>
#include <cctype>

using namespace std;
void printArray(vector<int>& arr) {
    for (auto i : arr) {
        cout << i << " ";
    }
    cout << endl;
}
class Solution {
    bool isAlphaNumeric(char c) {
        return isalnum(static_cast<unsigned char>(c));
    }
public:
    bool solve(string& s, int left, int right) {
        if (left >= right) {
            return true;
        }
        while ((left < s.size() && right >= 0) && (!isAlphaNumeric(s[left]) || !isAlphaNumeric(s[right]))) {
            if (!isAlphaNumeric(s[left])) left++;
            if (!isAlphaNumeric(s[right])) right--;

        }
        if (left == s.size() || right < 0) return true;
        char lowerLeftChar = tolower(s[left]);
        char lowerRightChar = tolower(s[right]);
        if (lowerLeftChar != lowerRightChar) {
            return false;
        }
        return solve(s, left + 1, right - 1);


    }
    bool isPalindrome(string s) {
        return solve(s, 0, s.size() - 1);
    }
};
int main()
{
    Solution obj;
    string s = "";
    cout << obj.isPalindrome(s) << endl;

    return 0;
}


class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int currentNumber = x;
        long long int reverseNumber = 0;
        while (currentNumber > 0){
            int lastDigit = currentNumber % 10;
            reverseNumber = (reverseNumber * 10) + lastDigit;
            currentNumber = currentNumber / 10;
        }
        if (x == reverseNumber){
            return true;
        }
        return false;
    }
};
// tc: O(log 10(x))

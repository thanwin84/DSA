class Solution {
public:
    bool armstrongNumber(int x) {
        int currentNumber = x;
        int newNumber = 0;
        while (currentNumber > 0 || currentNumber < -0) {
            int lastDigit = currentNumber % 10;
            newNumber += pow(lastDigit, 3);
            
            currentNumber = currentNumber / 10;
        }
        if (x == newNumber) {
            return true;
        }
        return false;
    }
};

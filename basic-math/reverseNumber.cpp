class Solution {   
public:
    bool isWithin32BitRange(long long num){
        return num >= INT_MIN && num <= INT_MAX;
    }
    int reverse(int x) {
        int currentValue = x;
        long long reverseNumber = 0;
        while (currentValue > 0 || currentValue < -0){
            int lastDigit = currentValue % 10;
            currentValue = currentValue / 10;
            reverseNumber = (reverseNumber * 10) + lastDigit;
        }
        if (!isWithin32BitRange(reverseNumber)){
            return 0;
        }
        return reverseNumber;
    }
};

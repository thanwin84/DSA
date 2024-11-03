lass Solution{
public:
    int evenlyDivides(int N){
        //code here
        int count = 0;
        int value = N;
        while (value > 0){
            int lastDigit = value % 10;
            if (lastDigit != 0 && N % lastDigit == 0){
                count++;
            }
            value = value / 10;
            
        }
        return count;
    }
};

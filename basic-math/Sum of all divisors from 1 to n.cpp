class Solution {
  public:
    long long sumOfDivisors(int n) {
        // Write Your Code here
        long long sum = 0;
        vector<int> divisorSums(n + 1, 0);
        for (int i = 1; i <= n; i++){
            for (int j = i; j <= n; j+= i){
                divisorSums[j] += i;
            }
        }
        for (int i = 0; i <= n; i++){
            sum += divisorSums[i];
        }
        return sum;
    }
};

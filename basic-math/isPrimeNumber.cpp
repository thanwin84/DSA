
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

using namespace std;
void printArray(vector<int>& arr) {
    for (auto i : arr) {
        cout << i << " ";
    }
    cout << endl;
}
class Solution {
public:
    bool isPrimeNumber(int n) {
        int count = 0;
        for (int i = 1; i <= sqrt(n); i++) {
            if (n % i == 0) {
                count++;
                // other part also has to be unique
                if (n / i != i) {
                    count++;
                }
            }
        }
        if (count == 2) {
            return true;
        }
        return false;
    }
};
int main()
{
    Solution obj;
    cout << obj.isPrimeNumber(6) << endl;
    return 0;
}
//tc: O(sqrt(n))

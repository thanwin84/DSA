
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
class Solve {
public:
    void extractDigit(int n) {
        vector<int> output;
        int value = n;
        while (value > 0) {
            output.push_back(value % 10);
            value = value / 10;
        }
        reverse(output.begin(), output.end());
        printArray(output);
   }
    
};

int main()
{
    Solve obj;
    obj.extractDigit(8431);
    return 0;
}



#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include<set>
#include <unordered_set>

using namespace std;
void printArray(vector<int>& arr) {
    for (auto i : arr) {
        cout << i << " ";
    }
    cout << endl;
}
class Solve {
public:
    vector<int> bubbleSort(vector<int>& arr) {
        int size = arr.size();
        bool swapped = false;
        for (int i = size - 1; i >= 1; i--) {
            
            for (int j = 0; j < i; j++) {
                if (arr[j + 1] < arr[j]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swapped = true;
                }
            }
            if (!swapped) {
                break;
            }
        }
        return arr;
    }
};

int main()
{
    vector<int> arr = { 20, 30, 4, 2, 8 };
    Solve obj;
    vector<int> output = obj.bubbleSort(arr);
    printArray(output);
    return 0;
}

// worst and average tc: O(n^2)
// best case: O(n) when the array is already sorted

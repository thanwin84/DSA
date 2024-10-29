
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
    vector<int> selectionSort(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++) {
            const int temp = arr[i];
            int _min = temp;
            int minIndex = i;
            for (int j = i; j < arr.size(); j++) {
                if (arr[j] < _min) {
                    _min = arr[j];
                    minIndex = j;
                }
            }
            arr[i] = _min;
            arr[minIndex] = temp;
        }
        return arr;
    }
};

int main()
{
    vector<int> arr = { 20, 30, 4, 2, 8 };
    Solve obj;
    vector<int> output = obj.selectionSort(arr);
    printArray(output);
    return 0;
}

// time complexity: O(n^2)

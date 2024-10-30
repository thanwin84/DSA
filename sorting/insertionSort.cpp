
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
    vector<int> insertionSort(vector<int>& arr) {
        for (int i = 1; i < arr.size(); i++) {
            int pickedElement = arr[i]; // element to insert into sorted part
            int hole = i; // tract position for inserting the element
            // shirt element in the sorted part until we find the right spot
            while (hole > 0 && arr[hole - 1] > pickedElement) {
                arr[hole] = arr[hole - 1];
                hole--;
            }
            // insert the picked element at the correct position
            arr[hole] = pickedElement;
        }
        return arr;
    }
};

int main()
{
    vector<int> arr = { 20, 30, 4,2, 8 };
    Solve obj;
    vector<int> output = obj.insertionSort(arr);
    printArray(output);
    return 0;
}


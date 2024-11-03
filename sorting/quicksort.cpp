
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
    void swap(vector<int>& arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    int partition(vector<int>& arr, int start, int end) {
        int partitionIndex = start;
        int pivot = arr[end];
        for (int i = start; i < end; i++) {
            if (arr[i] <= pivot) {
                swap(arr, partitionIndex, i);
                partitionIndex++;
            }
        }
        swap(arr, partitionIndex, end);
        return partitionIndex;
    }
    void quickSort(vector<int>& arr, int start, int end) {
        if (start >= end) {
            return;
        }
        int partitionIndex = partition(arr, start, end);
        quickSort(arr, start, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, end);
    }
    
};

int main()
{
    vector<int> arr = { 20, 30, 4,2, 2, 8 };
    Solve obj;
    obj.quickSort(arr, 0, arr.size() -1);
    printArray(arr);
    
    return 0;
}


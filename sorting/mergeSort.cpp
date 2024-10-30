
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
    vector<int> merge(vector<int>& left, vector<int>& right, vector<int>& mainArray) {
        int k = 0, i =0, j = 0;
        while (i < left.size() && j < right.size()) {
            if (left[i] <= right[j]) {
                mainArray[k] = left[i];
                i++;
                k++;
            }
            else {
                mainArray[k] = right[j];
                j++;
                k++;
            }
        }
        while (i < left.size()) {
            mainArray[k] = left[i];
            i++;
            k++;
        }
        while (j < right.size()) {
            mainArray[k] = right[j];
            j++;
            k++;
        }
        return mainArray;
    }
    vector<int> mergeSort(vector<int>& arr) {
        if (arr.size() < 2) {
            return arr;
        }
        int mid = arr.size() / 2;
        vector<int> left;
        vector<int> right;
        for (int i = 0; i < mid; i++) left.push_back(arr[i]);
        for (int i = mid; i < arr.size(); i++) right.push_back(arr[i]);
        left = mergeSort(left);
        right = mergeSort(right);
        merge(left, right, arr);
        return arr;
    }
    
};

int main()
{
    vector<int> arr = { 20, 30, 4,2, 8 };
    Solve obj;
    vector<int> output = obj.mergeSort(arr);
    printArray(output);
    cout << 5 / 2 << endl;
    return 0;
}


class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        // Code Here
        int firstLargest = INT_MIN;
        for (auto item: arr){
            firstLargest = max(item, firstLargest);
        }
        int _secondLargest = INT_MIN;
        for (auto &item: arr){
            if (item > _secondLargest && item != firstLargest){
                _secondLargest = item;
            }
        }
        if (_secondLargest == INT_MIN){
            return -1;
        }
        return _secondLargest;
    }
};

// tc: O(2n)
class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        // Code Here
        int firstLargest = arr[0];
        int secondLargest = -1;
        
        for (int i = 1; i < arr.size(); i++ ){
            if (arr[i] > firstLargest){
                secondLargest = firstLargest;
                firstLargest = arr[i];
            }
            else if (arr[i] < firstLargest && arr[i] > secondLargest){
                secondLargest = arr[i];
            }
        }
        
        
        return secondLargest;
    }
};
// tc: O(n)

class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        int _max = INT_MIN;
        for (auto item: arr){
            _max = max(_max, item);
        }
        return _max;
    }
};

class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        vector<int> result;
        for (int i = arr.size()-1; i >= 0; i--){
            if (result.empty()){
                result.push_back(arr[i]);
            }
            else {
                if (arr[i] >= result.back()){
                    result.push_back(arr[i]);
                }
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

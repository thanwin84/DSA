class Solution {
  public:
    vector<int> FirstNegativeInteger(vector<int>& arr, int k) {
        // write code here
        vector<int> ans;
        queue<int> q;
        int i = 0; 
        int j = 0;
        while (j < arr.size()){
            if (arr[j] < 0){
                q.push(arr[j]);
            }
            if (j - i + 1 < k){
                j++;
            }
            else {
                if (q.size() == 0){
                    ans.push_back(0);
                } else {
                    ans.push_back(q.front());
                }
                // slide the window
                if (!q.empty() && q.front() == arr[i]) q.pop();
                i++;
                j++;
            }
        }
        return ans;
    }
};
// time complexity: O(n)
// space: O(n) 

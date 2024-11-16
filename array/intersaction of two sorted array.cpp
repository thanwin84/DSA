class Solution{
  public:
      // Function to return a list containing the intersection of two arrays.
      vector<int> intersection(vector<int> &arr1, vector<int> &arr2) {
          int n1 = arr1.size(), n2 = arr2.size();
          vector<int> visited(n2, 0);
          vector<int> ans;
          for (int i = 0; i < n1; i++) {
              for (int j = 0; j < n2; j++) {
                  if (arr1[i] == arr2[j] && visited[j] == 0) {
                      ans.push_back(arr1[i]);
                      visited[j] = 1;
                      break;
                  }
              }
          }
          return ans;
      }
};
// tc: O(n^2) and space: O(max(n1, n2))

// two pointer approach
class Solution{
  public:
      // Function to return a list containing the intersection of two arrays.
      vector<int> intersection(vector<int> &arr1, vector<int> &arr2) {
          int n1 = arr1.size(), n2 = arr2.size();
          int left = 0, right = 0;
          vector<int> ans;
          while (left < n1 && right < n2) {
              if (arr1[left] < arr2[right]) left++;
              else if (arr2[right] < arr1[left]) right++;
              else {
                  if (ans.empty() || arr1[left] != ans.back()){
                      ans.push_back(arr1[left]);
                  }
                  left++;
                  right++;
              }
          }
          return ans;
      }
};
// tc: O(n1 + n2) and space: O(1)

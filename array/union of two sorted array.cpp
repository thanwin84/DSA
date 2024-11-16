//naive approach
// we can use set. we will push all the items to the set and at the we will have sorted unique element in set
// after that we can take all items from set and push it to an array
// tc: O(nlogn)

// optimal approach
class Solution{
  public:
      // a,b : the arrays
      // Function to return a list containing the union of the two arrays.
      vector<int> findUnion(vector<int> &a, vector<int> &b) {
          // Your code here
          // return vector with correct order of elements
          int left = 0;
          int right = 0;
          vector<int> union_arr;
          while (left < a.size() && right < b.size()) {
              if (a[left] <= b[right]) {
                  if (union_arr.empty() || union_arr.back() != a[left]) {
                      union_arr.push_back(a[left]);
                  }
                  left++;
              }
              else {
                  if (union_arr.empty() || union_arr.back() != b[right]) {
                      union_arr.push_back(b[right]);
                  }
                  right++;
              }
          }
          while (left < a.size()) {
              if (union_arr.empty() || union_arr.back() != a[left]) {
                  union_arr.push_back(a[left]);
              }
              left++;
          }
          while (right < b.size()) {
              if (union_arr.empty() || union_arr.back() != b[right]) {
                  union_arr.push_back(b[right]);
              }
              right++;
          }
          return union_arr;
      }
 };
// tc: O(n) where n is the size of a and b array.
// space: O(1)

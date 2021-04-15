#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  void traceback(vector<vector<int>>& rst, vector<int>& path,
                 vector<bool>& visited, const vector<int>& nums, const int n) {
    unordered_set<int> forbid;
    for (int i = 0; i < n; ++i) {
      if (!visited[i] && forbid.find(nums[i]) == forbid.end()) {
        path.push_back(nums[i]);
        visited[i] = true;
        forbid.insert(nums[i]);
        if (path.size() == n) {
          rst.push_back(path);
          visited[i] = false;
          path.pop_back();
          return;
        }
        traceback(rst, path, visited, nums, n);
        // for (int m : forbid) {
        //   cout << m << ' ';
        // }
        visited[i] = false;
        path.pop_back();
      }
    }
  }
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> rst;
    vector<int> path;
    int n = nums.size();
    vector<bool> visited(n, false);
    traceback(rst, path, visited, nums, n);
    return rst;
  }
};

int main() {
  vector<int> nums = {1, 1, 2};
  Solution sol;
  vector<vector<int>> rst = sol.permuteUnique(nums);
  for (vector<int> a : rst) {
    for (int m : a) {
      cout << m << ' ';
    }
    cout << endl;
  }
}
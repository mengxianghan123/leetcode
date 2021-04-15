// 几乎超时，难以置信自己可以写出这么笨的代码
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void backtrack(const vector<int>& candidates, const int n, const int target,
                 vector<int>& path, const int start, vector<vector<int>>& rst) {
    int sum = 0;
    for (int i : path) {
      sum += i;
    }
    if (sum == target) {
      vector<int> temp(path.begin(),path.end());
      sort(temp.begin(), temp.end());
      if (find(rst.begin(), rst.end(), temp) == rst.end()) {
        rst.push_back(temp);
        return;
      }
      return;
    }
    if (sum > target) {
      return;
    }
    for (int i = start; i < n; ++i) {
      path.push_back(candidates[i]);
      backtrack(candidates, n, target, path, i + 1, rst);
      path.pop_back();
    }
  }
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> rst;
    vector<int> path;
    int start = 0;
    int n = candidates.size();
    backtrack(candidates, n, target, path, start, rst);
    return rst;
  }
};

int main() {
  vector<int> candidates = {4,4,2,1,4,2,2,1,3};
  int target = 6;
  vector<vector<int>> rst;
  Solution sol;
  rst = sol.combinationSum2(candidates, target);
  for (auto m : rst) {
    for (auto n : m) {
      cout << n << ' ';
    }
    cout << '\n';
  }
}
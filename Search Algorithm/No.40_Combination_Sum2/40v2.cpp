// 这个版本好多了
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void backtrack(const vector<int>& candidates, const int n, const int target,
                 vector<int>& path, const int start, vector<vector<int>>& rst) {
    if (target == 0) {
      rst.push_back(path);
      return;
    }
    if (target < 0) {
      return;
    }
    for (int i = start; i < n; ++i) {
      if (i > start && candidates[i] == candidates[i - 1]) continue;
      path.push_back(candidates[i]);
      backtrack(candidates, n, target - path.back(), path, i + 1, rst);
      path.pop_back();
    }
  }
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> rst;
    vector<int> path;
    int start = 0;
    int n = candidates.size();
    sort(candidates.begin(),candidates.end());
    backtrack(candidates, n, target, path, start, rst);
    return rst;
  }
};

int main() {
  vector<int> candidates = {4, 4, 2, 1, 4, 2, 2, 1, 3};
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
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void backtracking(vector<int>& path, vector<vector<int>>& ans, const int& n,
                    const int k) {
    if (path.size() == k) {
      ans.push_back(path);
      return;
    }
    int beg;
    if (path.empty())
      beg = 1;
    else
      beg = path.back() + 1;
    for (; k - path.size() <= n - beg + 1; ++beg) {
      path.push_back(beg);
      backtracking(path, ans, n, k);
      path.pop_back();
    }
  }
  vector<vector<int>> combine(int n, int k) {
    vector<int> path;
    vector<vector<int>> ans;
    backtracking(path, ans, n, k);
    return ans;
  }
};

int main() {
  Solution sol;
  int n = 4, k = 2;
  vector<vector<int>> ans = sol.combine(n, k);
  for (auto i : ans) {
    for (auto j : i) {
      cout << j << ' ';
    }
    cout << endl;
  }
}
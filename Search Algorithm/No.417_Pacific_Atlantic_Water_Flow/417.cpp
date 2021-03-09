// 从海洋到陆地
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& reach, int i,
           int j) {
    if (reach[i][j]) return;
    reach[i][j] = true;
    if (i - 1 >= 0 && matrix[i - 1][j] >= matrix[i][j])
      dfs(matrix, reach, i - 1, j);
    if (i + 1 < matrix.size() && matrix[i + 1][j] >= matrix[i][j])
      dfs(matrix, reach, i + 1, j);
    if (j - 1 >= 0 && matrix[i][j - 1] >= matrix[i][j])
      dfs(matrix, reach, i, j - 1);
    if (j + 1 < matrix[0].size() && matrix[i][j + 1] >= matrix[i][j])
      dfs(matrix, reach, i, j + 1);
  }
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
    if(matrix.empty()) return {};
    int i = matrix.size();
    int j = matrix[0].size();
    vector<vector<bool>> can_reach_a(i, vector<bool>(j, false));
    vector<vector<bool>> can_reach_p(i, vector<bool>(j, false));
    for (int m = 0; m < j; ++m) {
      dfs(matrix, can_reach_p, 0, m);
      dfs(matrix, can_reach_a, i - 1, m);
    }
    for (int m = 0; m < i; ++m) {
      dfs(matrix, can_reach_p, m, 0);
      dfs(matrix, can_reach_a, m, j - 1);
    }
    vector<vector<int>> ans;
    for (int m = 0; m < i; ++m) {
      for (int n = 0; n < j; ++n) {
        if (can_reach_a[m][n] && can_reach_p[m][n]) {
          ans.push_back({m, n});
        }
      }
    }
    return ans;
  }
};

int main() {
  vector<vector<int>> matrix;
  matrix.push_back({1, 2, 2, 3, 5});
  matrix.push_back({3, 2, 3, 4, 4});
  matrix.push_back({2, 4, 5, 3, 1});
  matrix.push_back({6, 7, 1, 4, 5});
  matrix.push_back({5, 1, 1, 2, 4});
  Solution sol;
  vector<vector<int>> ans = sol.pacificAtlantic(matrix);
  for (auto i : ans) {
    cout << i.front() << " " << i.back() << endl;
  }
}
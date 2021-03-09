// 从陆地到海洋(没解决，太麻烦了，偷懒不写了)
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool search_temp(int i, int j, vector<vector<int>>& temp) {}
  void dfs2a(vector<vector<int>>& matrix, vector<vector<bool>>& map, int i,
             int j, vector<vector<int>>& temp) {
    temp.push_back({i, j});
    if (i == matrix.size() - 1 || j == matrix[0].size() - 1 || map[i][j]) {
      for (auto k : temp) {
        map[k[0]][k[1]] = true;
      }
    }
    if (i - 1 >= 0 && matrix[i - 1][j] <= matrix[i][j] &&
        !search_temp(i, j, temp)) {
      dfs2a(matrix, map, i - 1, j, temp);
    }
  }
  void dfs2p(vector<vector<int>>& matrix, vector<vector<bool>>& map, int i,
             int j, vector<vector<int>>& temp) {}
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
    vector<vector<int>> ans;
    vector<vector<bool>> map_a(matrix.size(),
                               vector<bool>(matrix[0].size(), false));
    vector<vector<bool>> map_p(matrix.size(),
                               vector<bool>(matrix[0].size(), false));
    vector<vector<int>> temp;
    for (int i = 0; i < matrix.size(); ++i) {
      for (int j = 0; j < matrix[0].size(); ++j) {
        dfs2a(matrix, map_a, i, j, temp);
        dfs2p(matrix, map_p, i, j, temp);
        if (map_p[i][j] && map_a[i][j]) ans.push_back({i, j});
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
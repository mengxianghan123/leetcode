// 借助递归解决
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void searchisland(vector<vector<int>>& grid, int i, int j, int& cnt) {
    if (i < 0 || j < 0 || i == grid.size() || j == grid[i].size() ||
        grid[i][j] == 0) {
      return;
    }
    ++cnt;
    grid[i][j] = 0;
    searchisland(grid, i - 1, j, cnt);
    searchisland(grid, i, j - 1, cnt);
    searchisland(grid, i + 1, j, cnt);
    searchisland(grid, i, j + 1, cnt);
  }
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int max_cnt = 0;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[i].size(); ++j) {
        if (grid[i][j] == 1) {
          int cnt = 0;
          searchisland(grid, i, j, cnt);
          max_cnt = max(max_cnt, cnt);
        }
      }
    }
    return max_cnt;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> grid;
  grid.push_back(vector<int>{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0});
  grid.push_back(vector<int>{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0});
  grid.push_back(vector<int>{0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0});
  grid.push_back(vector<int>{0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0});
  grid.push_back(vector<int>{0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0});
  grid.push_back(vector<int>{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0});
  grid.push_back(vector<int>{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0});
  grid.push_back(vector<int>{0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0});
  cout << sol.maxAreaOfIsland(grid) << endl;
}
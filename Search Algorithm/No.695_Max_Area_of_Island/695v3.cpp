// 广度优先搜索
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int i = grid.size();
    int j = grid[0].size();
    int max_cnt = 0;
    for (int m = 0; m < i; ++m) {
      for (int n = 0; n < j; ++n) {
        if (grid[m][n] == 1) {
          queue<pair<int, int>> myqueue;
          int cnt = 0;
          myqueue.push({m, n});
          grid[m][n] = 0;
          while (!myqueue.empty()) {
            auto temp = myqueue.front();
            int temp_m = temp.first;
            int temp_n = temp.second;
            myqueue.pop();
            ++cnt;
            if (temp_m - 1 >= 0 && grid[temp_m - 1][temp_n] == 1) {
              myqueue.push({temp_m - 1, temp_n});
              grid[temp_m - 1][temp_n] = 0;
            }
            if (temp_n - 1 >= 0 && grid[temp_m][temp_n - 1] == 1) {
              myqueue.push({temp_m - 1, temp_n});
              grid[temp_m][temp_n - 1] = 0;
            }
            if (temp_m + 1 < i && grid[temp_m + 1][temp_n] == 1) {
              myqueue.push({temp_m + 1, temp_n});
              grid[temp_m + 1][temp_n] = 0;
            }
            if (temp_n + 1 < j && grid[temp_m][temp_n + 1] == 1) {
              myqueue.push({temp_m, temp_n + 1});
              grid[temp_m][temp_n + 1] = 0;
            }
          }
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
  // vector<vector<int>> grid1;
  // grid1.push_back(vector<int>{1, 1, 0, 0, 0});
  // grid1.push_back(vector<int>{1, 1, 0, 0, 0});
  // grid1.push_back(vector<int>{0, 0, 0, 1, 1});
  // grid1.push_back(vector<int>{0, 0, 0, 1, 1});
  // cout << sol.maxAreaOfIsland(grid) << endl;
}
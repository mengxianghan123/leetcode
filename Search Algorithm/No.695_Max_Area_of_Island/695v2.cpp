// 借助堆栈解决
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int i = grid.size(), j = grid[0].size();
    int max_cnt = 0;
    for (int p = 0; p < i; ++p) {
      for (int q = 0; q < j; ++q) {
        if (grid[p][q] == 1) {
          stack<pair<int, int>> mystack;
          int cnt = 0;
          mystack.push({p, q});
          grid[p][q] = 0;
          while (!mystack.empty()) {
            pair<int, int> temp = mystack.top();
            int m = temp.first, n = temp.second;
            mystack.pop();
            ++cnt;
            if (m - 1 >= 0 && grid[m - 1][n] == 1) {
              mystack.push({m - 1, n});
              grid[m - 1][n] = 0;
            }
            if (n - 1 >= 0 && grid[m][n - 1] == 1) {
              mystack.push({m, n - 1});
              grid[m][n - 1] = 0;
            }
            if (m + 1 < i && grid[m + 1][n] == 1) {
              mystack.push({m + 1, n});
              grid[m + 1][n] = 0;
            }
            if (n + 1 < j && grid[m][n + 1] == 1) {
              mystack.push({m, n + 1});
              grid[m][n + 1] = 0;
            }
          }
          max_cnt = max(cnt, max_cnt);
        }
      }
    }
    return max_cnt;
  }
};

int main() {
  Solution sol;
  // vector<vector<int>> grid;
  // grid.push_back(vector<int>{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0});
  // grid.push_back(vector<int>{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0});
  // grid.push_back(vector<int>{0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0});
  // grid.push_back(vector<int>{0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0});
  // grid.push_back(vector<int>{0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0});
  // grid.push_back(vector<int>{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0});
  // grid.push_back(vector<int>{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0});
  // grid.push_back(vector<int>{0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0});
  // cout << sol.maxAreaOfIsland(grid) << endl;
  vector<vector<int>> grid1;
  grid1.push_back(vector<int>{1, 1, 0, 0, 0});
  grid1.push_back(vector<int>{1, 1, 0, 0, 0});
  grid1.push_back(vector<int>{0, 0, 0, 1, 1});
  grid1.push_back(vector<int>{0, 0, 0, 1, 1});
  cout << sol.maxAreaOfIsland(grid1) << endl;
}
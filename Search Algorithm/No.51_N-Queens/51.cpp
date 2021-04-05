#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  void backtracking(vector<string>& chessboard, int num,
                    vector<vector<string>>& rst, int i, int j,
                    vector<vector<bool>>& visited) {
    vector<vector<int>> mychange;
    chessboard[i][j] = 'Q';
    for (int m = 0; m < chessboard.size(); ++m) {
      for (int n = 0; n < chessboard[0].size(); ++n) {
        if ((m == i || n == j || (m - i) == (n - j) || (m - i) == (j - n)) &&
            (!visited[m][n]) && chessboard[m][n] != 'Q') {
          visited[m][n] = true;
          mychange.push_back({m, n});
        }
      }
    }
    --num;
    if (num == 0) {
      rst.push_back(chessboard);
      for (auto change : mychange) {
        visited[change[0]][change[1]] = false;
      }
      chessboard[i][j] = '.';
      return;
    }
    for (int n = 0; n < chessboard[0].size(); ++n) {
      if (!visited[i + 1][n]) {
        backtracking(chessboard, num, rst, i + 1, n, visited);
      }
    }
    for (auto change : mychange) {
      visited[change[0]][change[1]] = false;
    }
    chessboard[i][j] = '.';
    return;
  }

  vector<vector<string>> solveNQueens(int n) {
    vector<string> chessboard(n, string(n, '.'));
    vector<vector<string>> rst;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    for (int i = 0; i < n; ++i) {
      backtracking(chessboard, n, rst, 0, i, visited);
    }
    return rst;
  }
};

int main() {
  Solution sol;
  vector<vector<string>> rst = sol.solveNQueens(4);
  for (auto i : rst) {
    for (auto j : i) {
      for (auto m : j) {
        cout << m << ' ';
      }
      cout << endl;
    }
    cout << endl;
  }
}
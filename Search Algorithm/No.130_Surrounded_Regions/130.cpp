#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void dfs(int m, int n, vector<vector<bool>>& keep,
           const vector<vector<char>>& board) {
    if (m < 0 || n < 0 || m >= board.size() || n >= board[0].size()||keep[m][n]) return;
    if (board[m][n] == 'O') {
      keep[m][n] = true;
      dfs(m - 1, n, keep, board);
      dfs(m, n - 1, keep, board);
      dfs(m + 1, n, keep, board);
      dfs(m, n + 1, keep, board);
    }
  }
  void solve(vector<vector<char>>& board) {
    int m = board.size();
    int n = board[0].size();
    vector<vector<bool>> keep(m, vector<bool>(n, false));
    for (int i = 0; i < m; ++i) {
      if (board[i][0] == 'O') {
        dfs(i, 0, keep, board);
      }
    }
    for (int i = 0; i < m; ++i) {
      if (board[i][n - 1] == 'O') {
        dfs(i, n - 1, keep, board);
      }
    }
    for (int i = 0; i < n; ++i) {
      if (board[0][i] == 'O') {
        dfs(0, i, keep, board);
      }
    }
    for (int i = 0; i < n; ++i) {
      if (board[m - 1][i] == 'O') {
        dfs(m - 1, i, keep, board);
      }
    }

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (!keep[i][j] && board[i][j] == 'O') {
          board[i][j] = 'X';
        }
      }
    }
  }
};

int main() {
  vector<vector<char>> board{{'X', 'X', 'X', 'X'},
                             {'X', 'O', 'O', 'X'},
                             {'X', 'X', 'O', 'X'},
                             {'X', 'O', 'X', 'X'}};
  Solution sol;
  sol.solve(board);
  for (auto m : board) {
    for (auto n : m) {
      cout << n << ' ';
    }
    cout << endl;
  }
}
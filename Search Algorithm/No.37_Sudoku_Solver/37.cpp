// 没做完。。。
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void backtrack(vector<vector<char>>& board, vector<vector<char>>& rlgrid) {
    int min_cnt = 0, idx = 0;
    for (int i = 0; i < 27; ++i) {
      int cnt = 0;
      for (int j = 0; j < 9; ++j) {
        if (rlgrid[i][j] == '.') ++cnt;
      }
      if (cnt < min_cnt && cnt != 0) {
        min_cnt = cnt;
        idx = i;
      }
    }
  }

  void solveSudoku(vector<vector<char>>& board) {
    vector<vector<char>> rlgrid(board.begin(), board.end());
    for (int j = 0; j < 9; ++j) {
      vector<char> temp;
      for (int i = 0; i < 9; ++i) temp.push_back(board[i][j]);
      rlgrid.push_back(temp);
    }
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        rlgrid.push_back({board[i * 3][j * 3], board[i * 3][j * 3 + 1],
                          board[i * 3][j * 3 + 2], board[i * 3 + 1][j * 3],
                          board[i * 3 + 1][j * 3 + 1],
                          board[i * 3 + 1][j * 3 + 2], board[i * 3 + 2][j * 3],
                          board[i * 3 + 2][j * 3 + 1],
                          board[i * 3 + 2][j * 3 + 2]});
      }
    }
    backtrack(board, rlgrid);
  }
};

int main() {
  Solution sol;
  vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  sol.solveSudoku(board);
  for (auto i : board) {
    for (auto j : i) {
      cout << j << ' ';
    }
    cout << endl;
  }
}

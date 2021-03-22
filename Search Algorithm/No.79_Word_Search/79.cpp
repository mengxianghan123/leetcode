#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<pair<int, int>> change = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
  vector<pair<int, int>> used;
  bool check_in(pair<int, int> pos) {
    if (used.empty()) return false;
    for (auto i : used) {
      if (pos == i) return true;
    }
    return false;
  }
  bool check(vector<vector<char>>& board, const pair<int, int> pos,
             const string& word, const int idx) {
    // cout << pos.first << ' ' << pos.second << ' ' << idx << endl;
    if (idx == word.size()) return true;
    if (pos.first < 0 || pos.second < 0 || pos.first == board.size() ||
        pos.second == board[0].size())
      return false;
    if (check_in(pos)) return false;
    if (board[pos.first][pos.second] == word[idx]) {
      used.push_back({pos.first, pos.second});
      for (int m = 0; m < 4; ++m) {
        bool ans = check(
            board, {pos.first + change[m].first, pos.second + change[m].second},
            word, idx + 1);
        if (ans)
          return true;
      }
      used.pop_back();
      return false;
    } else
      return false;
  }
  bool exist(vector<vector<char>>& board, string word) {
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[0].size(); ++j) {
        bool rst = check(board, {i, j}, word, 0);
        if (rst) return true;
      }
    }
    return false;
  }
};

int main() {
  Solution sol;
  vector<vector<char>> board;
  board.push_back({'A', 'A', 'A','A', 'A', 'A'});
  board.push_back({'A', 'A', 'A','A', 'A', 'A'});
  board.push_back({'A', 'A', 'A','A', 'A', 'A'});
  board.push_back({'A', 'A', 'A','A', 'A', 'A'});
  board.push_back({'A', 'A', 'A','A', 'A', 'A'});
  board.push_back({'A', 'A', 'A','A', 'A', 'A'});

  string word = "AAAAAAAAAAAAAAB";
  cout << sol.exist(board, word) << endl;
}
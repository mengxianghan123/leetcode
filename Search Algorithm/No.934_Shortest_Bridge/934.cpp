#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> directions = {0, -1, 0, 1, 0};
  void dfs(vector<vector<int>>& A, int i, int j, queue<vector<int>>& myqueue,
           int p, int q) {
    if (i < 0 || i >= p || j < 0 || j >= q || A[i][j] == 2) return;
    if (A[i][j] == 0) {
      myqueue.push({i, j});
      return;
    }
    A[i][j] = 2;
    dfs(A, i - 1, j, myqueue, p, q);
    dfs(A, i, j - 1, myqueue, p, q);
    dfs(A, i + 1, j, myqueue, p, q);
    dfs(A, i, j + 1, myqueue, p, q);
  }

  int shortestBridge(vector<vector<int>>& A) {
    int p = A.size(), q = A[0].size();
    queue<vector<int>> myqueue;
    bool flipped = false;
    for (int i = 0; i < p; ++i) {
      if (flipped) break;
      for (int j = 0; j < q; ++j)
        if (A[i][j] == 1) {
          dfs(A, i, j, myqueue, p, q);
          flipped = true;
          break;
        }
    }
    int num = 0;
    int x, y;
    while (true) {
      int len_queue = myqueue.size();
      ++num;
      for (; len_queue > 0; --len_queue) {
        vector<int> temp = myqueue.front();
        myqueue.pop();
        for (int k = 0; k < 4; ++k) {
          x = temp[0] + directions[k];
          y = temp[1] + directions[k + 1];
          if (x >= 0 && x < p && y >= 0 && y < q && A[x][y] != 2) {
            if (A[x][y] == 1) return num;
            myqueue.push({x, y});
            A[x][y] = 2;
          }
        }
      }
    }
  }
};

int main() {
  Solution sol;
  vector<vector<int>> A;
  A.push_back({0, 0, 0, 0, 0, 0});
  A.push_back({0, 1, 0, 0, 0, 0});
  A.push_back({1, 1, 0, 0, 0, 0});
  A.push_back({1, 1, 0, 0, 0, 0});
  A.push_back({0, 0, 0, 0, 0, 0});
  A.push_back({0, 0, 1, 1, 0, 0});

  int rst = sol.shortestBridge(A);
  cout << rst << endl;
}
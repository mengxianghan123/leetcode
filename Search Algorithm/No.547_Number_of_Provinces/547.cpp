// 深度优先搜索
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void checkCircle(vector<vector<int>>& isConnected, int i) {
    for (int m = 0; m < isConnected.size(); ++m) {
      if (isConnected[i][m] == 1) {
        isConnected[i][m] = 0;
        isConnected[m][i] = 0;
        checkCircle(isConnected, m);
      }
    }
  }

  int findCircleNum(vector<vector<int>>& isConnected) {
    int cnt = 0;
    int num = isConnected.size();
    for (int i = 0; i < num; ++i) {
      if (isConnected[i] != vector<int>(num, 0)) {
        ++cnt;
        checkCircle(isConnected, i);
      }
    }
    return cnt;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> isConnected = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
  cout << sol.findCircleNum(isConnected) << endl;
}
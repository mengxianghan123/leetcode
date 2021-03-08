// 增加了一个visited表可以查，区别不大
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void checkCircle(vector<vector<int>>& isConnected, int i,
                   vector<bool>& check) {
    for (int m = 0; m < isConnected.size(); ++m) {
      if (isConnected[i][m] == 1) {
        isConnected[i][m] = 0;
        checkCircle(isConnected, m, check);
      }
    }
    check[i] = true;
  }

  int findCircleNum(vector<vector<int>>& isConnected) {
    int cnt = 0;
    int num = isConnected.size();
    vector<bool> check(num, false);
    for (int i = 0; i < num; ++i) {
      if (!check[i]) {
        ++cnt;
        checkCircle(isConnected, i, check);
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
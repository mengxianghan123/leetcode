// 普通解法，空间复杂度可以优化
#include <windows.h>

#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int climbStairs(int n) {
    if (n <= 2) {
      return n;
    }
    vector<int> mylist(n + 1, 1);
    for (int i = 2; i < n + 1; ++i) {
      mylist[i] = mylist[i - 1] + mylist[i - 2];
    }
    return mylist.back();
  }
};

int main() {
  auto start = GetTickCount();
  Solution sol;
  cout << sol.climbStairs(30) << endl;
  auto timespend = GetTickCount() - start;
  cout << timespend << endl;
}
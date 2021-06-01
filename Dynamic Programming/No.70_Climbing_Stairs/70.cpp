// 递归，时间复杂度就离谱
#include <windows.h>

#include <iostream>
using namespace std;

class Solution {
 public:
  int climbStairs(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    return climbStairs(n - 1) + climbStairs(n - 2);
  }
};

int main() {
  Solution sol;
  auto start = GetTickCount();
  cout << sol.climbStairs(30) << endl;
  auto end = GetTickCount();
  cout <<  end - start<< endl;
}
// 空间复杂度优化版
#include <windows.h>

#include <iostream>
using namespace std;

class Solution {
 public:
  int climbStairs(int n) {
    if (n <= 2) {
      return n;
    }
    int num1 = 1;
    int num2 = 2;
    int sum;
    while (n-- > 2) {
      sum = num1 + num2;
      num1 = num2;
      num2 = sum;
    }
    return sum;
  }
};

int main() {
  auto start = GetTickCount();
  Solution sol;
  cout << sol.climbStairs(30) << endl;
  auto timespend = GetTickCount() - start;
  cout << timespend << endl;
}
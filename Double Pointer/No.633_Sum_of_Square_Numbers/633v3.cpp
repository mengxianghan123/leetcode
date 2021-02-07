// 双指针法
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool judgeSquareSum(int c) {
    long long r = floor(sqrt(c));
    long long l = 0;
    while (l <= r) {
      if (l*l + r*r == c) return true;
      if (l*l + r*r < c)
        ++l;
      else
        --r;
    }
    return false;
  }
};
int main() {
  Solution sol;
  cout << sol.judgeSquareSum(5) << endl;
}
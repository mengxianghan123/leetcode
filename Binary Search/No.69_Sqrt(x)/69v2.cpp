// 二分查找法二（留意）
#include <iostream>

using namespace std;

class Solution {
 public:
  int mySqrt(int x) {
    long long start = 0, end = (long long)x + 1;
    while (start != end) {
      long long mid = (start + end) / 2;
      if (mid * mid <= x) {
        start = mid + 1;
      } else {
        end = mid;
      }
    }
    return start - 1;
    //满足条件mid * mid <= x的永远出现在start/end重合位置的左侧
  }
};

int main() {
  Solution sol;
  cout << sol.mySqrt(8) << endl;
}
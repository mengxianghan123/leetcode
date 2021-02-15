// 二分查找法一
#include <iostream>

using namespace std;

class Solution {
 public:
  int mySqrt(int x) {
    long long start = 0, end = (long long)x + 1;
    while (start != end) {
      long long mid = (start + end) / 2;
      if (mid * mid <= x && (mid + 1) * (mid + 1) > x)
        return mid;
      else if ((mid + 1) * (mid + 1) <= x) {
        start = mid + 1;
      } else {
        end = mid;
      }
    }
    return 0;
  }
};

int main() {
  Solution sol;
  cout << sol.mySqrt(1) << endl;
}
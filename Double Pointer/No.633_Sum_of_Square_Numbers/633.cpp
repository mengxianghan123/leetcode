// 双指针法（预存平方结果）
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool judgeSquareSum(int c) {
    long long n = floor(sqrt(c));
    vector<long long> num;
    long long i = 0;
    while (i <= n) {
      num.push_back(i * i);
      ++i;
    }
    int l = 0, r = n;
    while (l <= r) {
      if (num[l] + num[r] == c) return true;
      if (num[l] + num[r] < c)
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
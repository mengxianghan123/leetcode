// 二分法
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int binaryfind(int start, int target, vector<int>& num) {
    int end = num.size();

    while (start != end) {
      int mid = (start + end) / 2;
      if (num[mid] == target) return mid;
      if (num[mid] > target)
        end = mid;
      else
        start = mid + 1;
    }
    return num.size();
  }

  bool judgeSquareSum(int c) {
    int n = floor(sqrt(c));
    vector<int> num;
    int i = 0;
    while (i <= n) {
      num.push_back(i * i);
      ++i;
    }
    for (int i = 0; i < n + 1; ++i) {
      int ans = binaryfind(i, c - num[i], num);
      if (ans == n + 1)
        continue;
      else
        return true;
    }
    return false;
  }
};
int main() {
  Solution sol;
  cout << sol.judgeSquareSum(0) << endl;
}
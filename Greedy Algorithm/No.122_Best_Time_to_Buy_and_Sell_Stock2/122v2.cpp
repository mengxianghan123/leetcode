// 双指针
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int start = 0, end = 0;
    int sum = 0;
    while (end != prices.size()) {
      if (end == prices.size() - 1) {
        if (end == start)
          break;
        else {
          sum += prices[end] - prices[start];
          break;
        }
      }
      if (prices[end + 1] >= prices[end]) {
        ++end;
      } else if (prices[end + 1] < prices[end]) {
        if (start == end) {
          ++start;
          ++end;
        } else {
          sum += prices[end] - prices[start];
          start = end + 1;
          ++end;
        }
      }
    }
		return sum;
  }
};

int main() {
  vector<int> a = {1, 9, 6, 9, 1, 7, 1, 1, 5, 9, 9, 9};
  Solution sol;
  cout << sol.maxProfit(a) << endl;
}
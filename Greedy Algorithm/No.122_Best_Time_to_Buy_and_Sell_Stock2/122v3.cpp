// 官方题解
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int ans = 0;
    int n = prices.size();
    for (int i = 1; i < n; ++i) {
      ans += max(0, prices[i] - prices[i - 1]);
    }
    return ans;
  }
};

int main() {
  vector<int> a = {1, 9, 6, 9, 1, 7, 1, 1, 5, 9, 9, 9};
  Solution sol;
  cout << sol.maxProfit(a) << endl;
}
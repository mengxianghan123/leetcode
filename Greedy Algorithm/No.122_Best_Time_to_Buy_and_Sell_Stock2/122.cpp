// 有点啰嗦的方法
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    if (prices.size() < 2) return 0;
    vector<int> distance;
    for (int i = 1; i < prices.size(); ++i) {
      distance.push_back(prices[i] - prices[i - 1]);
    }
    int state = 0;
    vector<int> wanted;
    for (int i = 0; i < distance.size(); ++i) {
      if (state <= 0 && distance[i] > 0) {
        wanted.push_back(i);
        state = 1;
      } else if (state > 0 && distance[i] < 0) {
        wanted.push_back(i);
        state = -1;
      }
      if (state > 0 && i == (distance.size() - 1) && distance[i] >= 0) {
        wanted.push_back(i + 1);
      }
    }
    int sum = 0;
    for (int i = 1; i < wanted.size(); ++i) {
      if (i % 2 == 1) {
        sum += prices[wanted[i]] - prices[wanted[i - 1]];
      }
    }
    return sum;
  }
};

int main() {
  vector<int> a = {1,9,6,9,1,7,1,1,5,9,9,9};
  Solution sol;
  cout << sol.maxProfit(a) << endl;
}
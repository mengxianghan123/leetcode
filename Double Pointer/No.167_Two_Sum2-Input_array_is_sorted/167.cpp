// 暴力法，超时了
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    for (auto beg = numbers.begin(); beg != numbers.end() - 1; ++beg) {
      auto get = find(beg + 1, numbers.end(), target - *beg);
      if (get != numbers.end()) {
        vector<int> rst;
        rst.push_back(beg - numbers.begin() + 1);
        rst.push_back(get - numbers.begin() + 1);
        return rst;
      }
    }
  }
};

int main() {
  vector<int> numbers = {-1,0};
  int target = -1;
  Solution sol;
  vector<int> rst = sol.twoSum(numbers, target);
  cout << rst[0] << ' ' << rst[1] << endl;
}
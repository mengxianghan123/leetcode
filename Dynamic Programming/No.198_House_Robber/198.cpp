// 空间压缩版
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int rob(vector<int>& nums) {
    if (nums.size() <= 2) {
      return max(nums.front(), nums.back());
    }
    int num_1 = nums[0];
    int num_2 = max(nums[0], nums[1]);
    int m = 1;
    while (++m < nums.size()) {
      int temp = max(num_1 + nums[m], num_2);
      num_1 = num_2;
      num_2 = temp;
    }
    return num_2;
  }
};

int main() {
  vector<int> nums = {2,7,9,3,1};
  Solution sol;
  cout << sol.rob(nums) << endl;
}
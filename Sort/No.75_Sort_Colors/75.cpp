// 遍历两次，先调整0的位置，再调整1的位置
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void sortColors(vector<int> &nums) {
    int ptr = 0;
    for (int &i : nums) {
      if (i == 0) {
        swap(nums[ptr], i);
        ++ptr;
      }
    }
    for (int &i : nums) {
      if (i == 1) {
        swap(nums[ptr], i);
        ++ptr;
      }
    }
  }
};

int main() {
  Solution sol;
  vector<int> nums = {2, 0, 2, 1, 1, 0};
  sol.sortColors(nums);
  for (auto i : nums) {
    cout << i << ' ';
  }
}
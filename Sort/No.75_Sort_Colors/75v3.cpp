// 遍历一次，同时定位0和2
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void sortColors(vector<int> &nums) {
    int ptr_0 = 0, ptr_2 = nums.size() - 1;
    for (int i = 0; i <= ptr_2; ++i) {
      if (nums[i] == 0) {
        swap(nums[ptr_0++], nums[i]);
      } else if (nums[i] == 2) {
        while (nums[i] != 1 && i <= ptr_2) {
          if (nums[i] == 0) {
            swap(nums[ptr_0++], nums[i]);
            break;
          } else if (nums[i] == 2) {
            swap(nums[ptr_2--], nums[i]);
          }
        }
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
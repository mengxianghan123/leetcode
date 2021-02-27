// 选择排序(求vector最小/最大值可以用min_element/max_element函数，位于algorithm下)
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void selection_sort(vector<int>& nums) {
    for (int i = 0; i < nums.size() - 1; ++i) {
      int temp = i;
      for (int j = i; j < nums.size(); ++j) {
        if (nums[j] < nums[temp]) temp = j;
      }
      swap(nums[i], nums[temp]);
    }
  }
};

int main() {
  Solution sol;
  vector<int> nums = {1, 10, 5, 2, 7, 9, 3, 4, 6, 8};
  sol.selection_sort(nums);
  for (int i : nums) {
    cout << i << " ";
  }
}

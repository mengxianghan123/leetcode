// 快速排序 (我自己写的，可以优化，更好的解法见readme.md)
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void quick_sort(vector<int>& nums, int start, int end) {
    int key = nums[start];
    int l = start, r = end;
    while (l < r) {
      for (; l != r && nums[r] > key; --r)
        ;
      if (l != r)
        nums[l] = nums[r];
      else {
        nums[l] = key;
        quick_sort(nums, start, l - 1);
        quick_sort(nums, l + 1, end);
        return;
      }
      for (; l != r && nums[l] < key; ++l)
        ;
      if (l != r)
        nums[r] = nums[l];
      else {
        nums[l] = key;
        quick_sort(nums, start, l - 1);
        quick_sort(nums, l + 1, end);
        return;
      }
    }
  }
};

int main() {
  Solution sol;
  vector<int> nums = {1, 10, 5, 2, 7, 9, 3, 4, 6, 8};
  sol.quick_sort(nums, 0, 9);
  for (int i : nums) {
    cout << i << " ";
  }
}

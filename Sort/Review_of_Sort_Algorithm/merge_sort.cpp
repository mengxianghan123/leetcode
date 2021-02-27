// 归并排序 (我自己写的，可以优化，更好的解法见readme.md)
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void merge_sort(vector<int> &nums, int start, int end) {
    if (start == end) return;
    merge_sort(nums, start, (start + end) / 2);
    merge_sort(nums, (start + end) / 2 + 1, end);
    vector<int> temp = {};
    int i = start, j = (start + end) / 2 + 1;
    while (i != (start + end) / 2 + 1 || j != end + 1) {
      if (i == (start + end) / 2 + 1) {
        temp.push_back(nums[j]);
        ++j;
      } else if (j == end + 1) {
        temp.push_back(nums[i]);
        ++i;
      } else {
        int m = min(nums[i], nums[j]);
        temp.push_back(m);
        if (m == nums[i])
          ++i;
        else
          ++j;
      }
    }
    i = 0;
    while (i < end - start + 1) {
      nums[start + i] = temp[i];
      ++i;
    }
    return;
  }
};

int main() {
  Solution sol;
  vector<int> nums = {1, 10, 5, 2, 7, 9, 3, 4, 6, 8};
  sol.merge_sort(nums, 0, 9);
  for (int i : nums) {
    cout << i << " ";
  }
}


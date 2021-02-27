// 冒泡排序
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void bubble_sort(vector<int>& nums) {
    bool isswap;
    for (int i = 1; i < nums.size(); ++i) {  //控制循环次数（只需要循环N-1次）
      isswap = false;
      for (
          int j = 1; j < nums.size() - i + 1;
          ++j) {  //控制一次循环时，冒泡的起点和终点。第i次循环，有i-1个数已经排序好
        if (nums[j] < nums[j - 1]) {
          swap(nums[j], nums[j - 1]);
          isswap = true;
        }
      }
      if(!isswap) break;
    }
  }
};

int main() {
  Solution sol;
  vector<int> nums = {1, 10, 5, 2, 7, 9, 3, 4, 6, 8};
  sol.bubble_sort(nums);
  for (int i : nums) {
    cout << i << " ";
  }
}

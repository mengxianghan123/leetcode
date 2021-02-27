// 插入排序 
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void insertion_sort(vector<int>& nums) {
    for (int i = 1; i < nums.size(); ++i) {
      for (int j = i; j > 0; --j) {
        if (nums[j] < nums[j - 1]) {
          swap(nums[j], nums[j - 1]);
        }
      }
    }
  }
};

int main() {
  Solution sol;
  vector<int> nums = {1, 10, 5, 2, 7, 9, 3, 4, 6, 8};
  sol.insertion_sort(nums);
  for (int i : nums) {
    cout << i << " ";
  }
}

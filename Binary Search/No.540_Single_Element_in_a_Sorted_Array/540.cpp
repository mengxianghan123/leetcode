#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int singleNonDuplicate(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
      int mid = (l + r) / 2;
      if ((mid - l + 1) % 2 == 0) {
        if(nums[mid]==nums[mid-1])
      }
    }
  }
};
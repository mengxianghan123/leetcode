#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  bool search(vector<int>& nums, int target) {
    int l = 0, r = nums.size();
    while (l != r) {
      int mid = (l + r) / 2;
      if (nums[mid] == target) {
        return true;
      }
      if (nums[mid] > nums[l]) {
        if (target < nums[mid] && target >= nums[l]) {
          r = mid;
        } else {
          l = mid + 1;
        }
      } else if (nums[mid] < nums[l]) {
        if (target > nums[mid] && target <= nums[r - 1]) {
          l = mid + 1;
        } else {
          r = mid;
        }
      } else {
        ++l;
      }
    }
    return false;
  }
};

int main() {
  vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
  int target = 5;
  Solution sol;
  cout << sol.search(nums, target) << endl;
}
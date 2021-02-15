#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    int l = 0, r = nums.size();
    int idx = -1;
    if (nums.empty()) return {-1, -1};
    while (l != r) {
      int mid = (l + r) / 2;
      if (nums[mid] == target) {
        idx = mid;
        break;
      } else if (nums[mid] < target)
        l = mid + 1;
      else
        r = mid;
    }
    if (idx == -1) return {-1, -1};
    int m = idx, n = idx;
    for (; m >= 0 && nums[m] == target; --m)
      ;
    for (; n < nums.size() && nums[n] == target; ++n)
      ;
    return {m + 1, n - 1};
  }
};

int main() {
  Solution sol;
  vector<int> nums = {};
  int target = 8;
  vector<int> ans = sol.searchRange(nums, target);
  for (int m : ans) {
    cout << m << endl;
  }
}
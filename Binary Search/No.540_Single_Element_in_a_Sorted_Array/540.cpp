// 通过左右区间元素个数奇偶判断所求元素所在区间
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int singleNonDuplicate(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    while (l != r) {
      int mid = l + (r - l) / 2;
      if (nums[mid] == nums[mid - 1]) {
        if ((mid - 1 - l) % 2 == 0) {
          l = mid + 1;
        } else {
          r = mid - 2;
        }
      } else if (nums[mid] == nums[mid + 1]) {
        if ((mid - l) % 2 == 0) {
          l = mid + 2;
        } else {
          r = mid - 1;
        }
      } else {
        return nums[mid];
      }
    }
    return nums[l];
  }
};

int main() {
  vector<int> nums = {3, 3, 7, 7, 10, 11, 11};
  Solution sol;
  cout << sol.singleNonDuplicate(nums) << endl;
}
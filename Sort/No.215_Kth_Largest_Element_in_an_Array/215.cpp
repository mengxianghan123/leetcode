#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int placeFirstElement(vector<int>& nums, int start, int end) {
    int m = rand() % (end - start) + start;
    swap(nums[m], nums[start]);
    int l = start, r = end - 1;
    int key = nums[l];
    while (l != r) {
      for (; nums[r] <= key && l != r; --r)
        ;
      nums[l] = nums[r];
      for (; nums[l] >= key && l != r; ++l)
        ;
      nums[r] = nums[l];
    }
    nums[l] = key;
    // for(int i : nums) cout<<i<<' ';
    return l + 1;
  }
  int findKthLargest(vector<int>& nums, int k) {
    int l = 0, r = nums.size();
    int idx = placeFirstElement(nums, l, r);
    while (idx != k) {
      if (idx < k) {
        l = idx;
        idx = placeFirstElement(nums, l, r);
      } else {
        r = idx - 1;
        idx = placeFirstElement(nums, l, r);
      }
    }
    return nums[idx - 1];
  }
};

int main() {
  vector<int> nums = {3, 2, 1, 5, 6, 4};
  int k = 2;
  Solution sol;
  cout << sol.findKthLargest(nums, k) << endl;
}
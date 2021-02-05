// 官方题解的最佳方案，省时省空间(代码是自己写的，肯定有优化空间)
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int pt1 = m - 1;
    int pt2 = n - 1;
    int p = m + n - 1;
    while (pt1 >= 0 && pt2 >= 0) {
      if (nums1[pt1] > nums2[pt2]) {
        nums1[p] = nums1[pt1];
        --pt1;
        --p;
      } else {
        nums1[p] = nums2[pt2];
        --pt2;
        --p;
      }
    }
    if (pt1 < 0) {
      while (pt2 >= 0) {
        nums1[p] = nums2[pt2];
        --p;
        --pt2;
      }
    }
  }
};

int main() {
  vector<int> nums1 = {1, 2, 3, 0, 0, 0};
  int m = 3;
  vector<int> nums2 = {2, 5, 6};
  int n = 3;
  Solution sol;
  sol.merge(nums1, m, nums2, n);
  for (auto i : nums1) {
    cout << i << ' ';
  }
}
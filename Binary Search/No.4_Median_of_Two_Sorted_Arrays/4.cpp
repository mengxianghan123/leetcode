#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int kthSmallNum(vector<int>& nums1, vector<int>& nums2, int k) {
    if (nums1.empty()) return nums2[k - 1];
    if (nums2.empty()) return nums1[k - 1];
    int p1 = 0, p2 = 0;
    while (k != 1 && p1 != nums1.size() && p2 != nums2.size()) {
      int idx = k / 2 - 1;
      int p1t, p2t;
      if (p1 + idx >= nums1.size()) {
        p2t = p2 + 2 * idx - nums1.size() + p1 + 1;
        p1t = nums1.size() - 1;
      } else if (p2 + idx >= nums2.size()) {
        p1t = p1 + 2 * idx - nums2.size() + p2 + 1;
        p2t = nums2.size() - 1;
      } else {
        p1t = p1 + idx;
        p2t = p2 + idx;
      }
      if (nums1[p1t] >= nums2[p2t]) {
        k -= p2t + 1 - p2;
        p2 = p2t + 1;

      } else {
        k -= p1t + 1 - p1;
        p1 = p1t + 1;
      }
    }
    if (p1 == nums1.size())
      return nums2[p2 + k - 1];
    else if (p2 == nums2.size())
      return nums1[p1 + k - 1];
    else {
      return min(nums1[p1], nums2[p2]);
    }
  }
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if ((nums1.size() + nums2.size()) % 2 == 0) {
      return (kthSmallNum(nums1, nums2, (nums1.size() + nums2.size()) / 2) +
              kthSmallNum(nums1, nums2,
                          (nums1.size() + nums2.size()) / 2 + 1)) /
             2.0;
    } else {
      return kthSmallNum(nums1, nums2, (nums1.size() + nums2.size()) / 2 + 1);
    }
  }
};

int main() {
  vector<int> nums1 = {1};
  vector<int> nums2 = {2,3,4,5,6};
  Solution sol;
  cout << sol.findMedianSortedArrays(nums1, nums2) << endl;
}
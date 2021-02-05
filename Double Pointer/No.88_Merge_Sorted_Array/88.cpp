// 该方法的缺点，有insert操作
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    // int num_zero = nums1.size() - m;
    nums1.erase(nums1.begin() + m, nums1.end());
    int pt1 = 0, pt2 = 0;
    while (pt1 < nums1.size() && pt2 < n) {
      if (nums1[pt1] <= nums2[pt2]) ++pt1;
      if (nums1[pt1] > nums2[pt2]) {
        nums1.insert(nums1.begin() + pt1, nums2[pt2]);
        ++pt1;
        ++pt2;
      }
    }
    nums1.insert(nums1.end(), nums2.begin() + pt2, nums2.end());
  }
};

int main() {
  vector<int> nums1 = {1,2,3,0,0,0};
  int m = 3;
  vector<int> nums2 = {2,5,6};
  int n = 3;
  Solution sol;
  sol.merge(nums1, m, nums2, n);
  for (auto i : nums1) {
    cout << i << ' ';
  }
}
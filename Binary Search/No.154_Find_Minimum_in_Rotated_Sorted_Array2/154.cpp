#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  int findMin(vector<int>& nums) {
    int low = 0;
    int high = nums.size() - 1;
    while (low < high) {
      int pivot = low + (high - low) / 2;
      if (nums[pivot] < nums[high]) {
        high = pivot;
      } else if (nums[pivot] > nums[high]) {
        low = pivot + 1;
      } else {
        high -= 1;
      }
    }
    return nums[low];
  }
};

int main() {
  vector<int> nums = {3, 5, 1};
  Solution sol;
  cout << sol.findMin(nums) << endl;
}
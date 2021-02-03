#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool checkPossibility(vector<int>& nums) {
    int cnt = 0;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] < nums[i - 1]) {
        if (cnt == 1) return false;
        if (i == 1 || i == nums.size() - 1)
          ++cnt;
        else {
          if (nums[i - 2] <= nums[i] || nums[i + 1] >= nums[i - 1]) {
            ++cnt;
          } else
            return false;
        }
      }
    }
    return true;
  }
};

int main() {
  vector<int> a = {4, 2, 1};
  Solution sol;
  cout << sol.checkPossibility(a) << endl;
}
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int rob(vector<int>& nums) {
    if (nums.size() < 3) {
      return max(nums.front(), nums.back());
    }
    vector<int> mylist(nums);
    mylist[1] = max(mylist[0], mylist[1]);
    for (int i = 2; i < mylist.size(); ++i) {
      mylist[i] = max(mylist[i] + mylist[i - 2], mylist[i - 1]);
    }
    return mylist.back();
  }
};

int main() {
  vector<int> nums = {2, 7, 9, 3, 1};
  Solution sol;
  cout << sol.rob(nums) << endl;
}
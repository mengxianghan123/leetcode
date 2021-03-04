// 遍历一次，同时定位0和1
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void sortColors(vector<int> &nums) {
    int ptr_0 = 0, ptr_1 = 0;
    int i = 0;
    while(i!=nums.size()){
      if(nums[i]==1){
        swap(nums[i],nums[ptr_1]);
        ++ptr_1;
        ++i;
      }
      else if(nums[i]==0){
        swap(nums[i],nums[ptr_0]);
        ++ptr_0;
        if(nums[i]==1){
          swap(nums[i],nums[ptr_1]);
          ++ptr_1;
          ++i;
        }
        else{
          ++ptr_1;
          ++i;
        }
      }
      else{
        ++i;
      }
    }
  }
};

int main() {
  Solution sol;
  vector<int> nums = {2, 0, 2, 1, 1, 0};
  sol.sortColors(nums);
  for (auto i : nums) {
    cout << i << ' ';
  }
}
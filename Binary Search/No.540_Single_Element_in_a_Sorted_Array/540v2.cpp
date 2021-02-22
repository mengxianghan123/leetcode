// 通过重复数字与mid的位置关系判断所求数字所在区间
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int singleNonDuplicate(vector<int>& nums) {
     int l = 0, r = nums.size()-1;
     while(l!=r){
       int mid = l + (r - l)/2;
       if(mid%2==1) --mid;
       if(nums[mid]==nums[mid+1]){
         l = mid + 2;
       }
       else if (mid > l && nums[mid]==nums[mid- 1]){
         r = mid - 2;
       }
       else{
         return nums[mid];
       }
     }
     return nums[l];
  }
};

int main() {
  vector<int> nums = {3,3,7,7,11,11,10};
  Solution sol;
  cout << sol.singleNonDuplicate(nums) << endl;
}
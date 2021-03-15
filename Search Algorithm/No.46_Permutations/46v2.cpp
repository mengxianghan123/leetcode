// 采用swap交换，更好的空间复杂度
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void backtracking(int first, vector<int>& nums,vector<vector<int>>& ans) {
    if(first==nums.size()-1) {
      ans.push_back(nums);
      return;
    }
    for(int i = first; i<nums.size();++i){
      swap(nums[i],nums[first]);
      backtracking(first+1,nums,ans);
      swap(nums[i],nums[first]);
    }
    
  }
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    backtracking(0,nums,ans);
    return ans;
  }
};

int main() {
  Solution sol;
  vector<int> nums = {1, 2, 3};
  vector<vector<int>> ans = sol.permute(nums);
  for (auto i : ans) {
    for (auto j : i) {
      cout << j << ' ';
    }
    cout << endl;
  }
}
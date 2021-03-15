// 用used向量存储哪些元素没用过
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void backtracking(vector<int>& path, vector<bool>& used, vector<int>& nums,
                    vector<vector<int>>& ans) {
    if (path.size() == used.size()) {
      ans.push_back(path);
      return;
    }
    for (int i = 0; i < used.size(); ++i) {
      if (used[i]) continue;
      used[i] = true;
      path.push_back(nums[i]);
      backtracking(path, used, nums, ans);
      used[i] = false;
      path.pop_back();
    }
  }
  vector<vector<int>> permute(vector<int>& nums) {
    vector<int> path;
    vector<bool> used(nums.size(), false);
    vector<vector<int>> ans;
    backtracking(path, used, nums, ans);
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
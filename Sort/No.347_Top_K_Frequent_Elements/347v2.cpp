// 采用先存unordered_map再桶排序
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> mymap;
    for (int i : nums) {
      ++mymap[i];
    }
    vector<vector<int>> cnt(nums.size()+1);
    for (pair<int, int> i : mymap) {
      cnt[i.second].push_back(i.first);
    }

    vector<int> rst;
    for (int i = cnt.size() - 1; i >= 0; --i) {
      if (!cnt[i].empty()) {
        for (int j : cnt[i]) {
          if (k > 0) {
            --k;
            rst.push_back(j);
          }
          else{
            break;
          }
        }
      }
    }
    return rst;
  }
};

int main() {
  Solution sol;
  vector<int> nums = {1,1,1,2,2,3};
  int k = 2;
  vector<int> rst = sol.topKFrequent(nums, k);
  for (int i : rst) {
    cout << i << " ";
  }
}
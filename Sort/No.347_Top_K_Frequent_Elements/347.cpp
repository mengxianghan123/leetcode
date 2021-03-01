// 采用先存unordered_map再调用sort的方式，时间复杂度可能不满足要求
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
      if (mymap.find(i) == mymap.end()) {
        mymap[i] = 1;
      } else {
        ++mymap[i];
      }
    }
    // 上面的条件分支可以被++mymap[i];一句话替代
    vector<pair<int, int>> temp;
    for (pair<int, int> i : mymap) {
      temp.push_back(i);
    }

    sort(temp.begin(), temp.end(),
         [](const pair<int, int>& a, const pair<int, int>& b) {
           return a.second > b.second;
         });

    vector<int> rst;

    for (auto j = temp.begin(); j < temp.begin() + k; ++j) {
      rst.push_back(j->first);
    }
    return rst;
  }
};

int main() {
  Solution sol;
  vector<int> nums = {1};
  int k = 1;
  vector<int> rst = sol.topKFrequent(nums, k);
  for (int i : rst) {
    cout << i << " ";
  }
}
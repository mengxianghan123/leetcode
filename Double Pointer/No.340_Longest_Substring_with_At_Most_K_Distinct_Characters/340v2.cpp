// 双指针，滑动窗
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int cntnotzero(vector<int> a) {
    int cnt = 0;
    for (int i : a) {
      if (i != 0) ++cnt;
    }
    return cnt;
  }

  int lengthOfLongestSubstringKDistinct(string s, int k) {
    int l = 0, r = -1;
    int best_len = 0;
    vector<int> nums(128, 0);
    while (r < int(s.size())) {
      ++nums[s[++r]];
      best_len = max(best_len, r - l);
      while (cntnotzero(nums) == k + 1) {
        --nums[s[l++]];
        
      }
    }
    return best_len;
  }
};

int main() {
  string s = "aa";
  int k = 1;
  Solution sol;
  cout << sol.lengthOfLongestSubstringKDistinct(s, k) << endl;
}
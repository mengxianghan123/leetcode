// 暴力法
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstringKDistinct(string s, int k) {
    int len_best = 0;
    for (int i = 0; i < s.size(); ++i) {
      int j = i;
      int cnt = 0;
      vector<bool> exist(128, false);
      while (cnt <= k && j < s.size()) {
        ++j;
        if (!exist[s[j - 1]]) {
          exist[s[j - 1]] = true;
          ++cnt;
        }
      }
      if (cnt > k) {
        len_best = max(j - 1 - i, len_best);
      } else {
        len_best = max(j - i, len_best);
      }
    }
    return len_best;
  }
};

int main() {
  string s = "aa";
  int k = 1;
  Solution sol;
  cout << sol.lengthOfLongestSubstringKDistinct(s, k) << endl;
}
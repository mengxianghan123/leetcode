#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  string minWindow(string s, string t) {
    vector<int> need(128, 0);
    vector<bool> exist(128, false);
    for (int i = 0; i < t.size(); ++i) {
      ++need[t[i]];
      exist[t[i]] = true;
    }
    int l = 0, r = 0;

    int cnt = 0;
    for (auto i : exist) {
      if (i) ++cnt;
    }

    int length = s.size() + 1, start = 0;

    while (r <= s.size()) {
      if (cnt != 0) {
        ++r;
        if (exist[s[r - 1]]) {
          if (!(--need[s[r - 1]])) --cnt;
        }
      } else {
        while (cnt == 0) {
          ++l;
          if (exist[s[l - 1]])
            if ((++need[s[l - 1]]) > 0) {
              ++cnt;
              length = min(r - l + 1, length);
              if (length == r - l + 1) start = l - 1;
            }
        }
      }
    }
    if (length == s.size() + 1)
      return "";
    else
      return s.substr(start, length);
  }
};

int main() {
  string s = "ADOBECODEBANC", t = "ABC";
  Solution sol;
  string rst = sol.minWindow(s, t);
  cout << rst << endl;
}
// 双指针+递归，时间复杂度高
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool func(string s) {
    int l = 0, r = s.size() - 1;
    while (l <= r) {
      if (s[l] == s[r]) {
        ++l;
        --r;
      } else
        return false;
    }
    return true;
  }
  bool validPalindrome(string s) {
    if (s.empty()) return true;
    int l = 0, r = s.size() - 1;
    while (l <= r) {
      if (s[l] == s[r]) {
        ++l;
        --r;
      } else {
        return func(s.substr(l, r - l)) || func(s.substr(l + 1, r - l));
      }
    }
    return true;
  }
};

int main() {
  string a = "ebcbbececabbacecbbcbe";
  Solution sol;
  cout << sol.validPalindrome(a) << endl;
}
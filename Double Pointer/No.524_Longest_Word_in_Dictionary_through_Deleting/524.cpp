#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  string findLongestWord(string s, vector<string>& d) {
    sort(d.begin(), d.end(), [](string& a, string& b) {
      return a.size() > b.size() || (a.size() == b.size() && a < b);
    });
    for (string i : d) {
      int l = 0, r = 0;
      while (r < i.size()) {
        if (l >= s.size()) break;
        if (s[l] == i[r]) {
          ++l;
          ++r;
        } else {
          ++l;
        }
      }
      if (r == i.size()) return i;
    }
    return "";
  }
};

int main() {
  Solution sol;
  string s = "abpcplea";
  vector<string> d = {"a", "b", "c"};
  cout << sol.findLongestWord(s, d) << endl;
}
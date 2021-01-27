#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
  int findContentChildren(vector<int> &g, vector<int> &s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int cnt = 0;
    auto it_g = g.begin();
    for (auto it_s = s.begin(); it_s != s.end() && it_g != g.end(); ++it_s) {
      if (*it_g <= *it_s) {
        ++cnt;
        ++it_g;
      }
    }
    return cnt;
  }
};
int main() {
  vector<int> g = {1, 2};
  vector<int> s = {1, 2, 3};
  Solution sol;
  cout << sol.findContentChildren(g, s) << endl;
}
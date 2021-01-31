// 暴力法。应该是对的，但是leetcode超时
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    int oper_num = 0;

    while (true) {
      vector<int> score(intervals.size(), 0);
      vector<int> ones(intervals.size(), 1);
      for (auto slice : intervals) {
        for (auto slice_2 : intervals) {
          if (slice.front()<slice_2.back() && slice.back()>slice_2.front())
            ++score[find(intervals.begin(), intervals.end(), slice) -
                    intervals.begin()];
        }
      }
      //   for (auto i:score) cout<<i<<' ';
      if (score == ones) return oper_num;
      intervals.erase(max_element(score.begin(), score.end()) - score.begin() +
                          intervals.begin(),
                      max_element(score.begin(), score.end()) - score.begin() +
                          intervals.begin() + 1);
      ++oper_num;
    }
  }
};

int main() {
  vector<vector<int>> a;
  vector<int> m = {1, 2};
  vector<int> n = {2, 3};
//   vector<int> o = {1, 2};
//   vector<int> p = {1, 3};

  a.push_back(m);
  a.push_back(n);
//   a.push_back(o);
//   a.push_back(p);

  Solution sol;
  cout << sol.eraseOverlapIntervals(a) << endl;
}
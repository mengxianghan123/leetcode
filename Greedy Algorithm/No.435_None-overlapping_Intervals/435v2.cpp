#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

bool sortthisvec(vector<int>& vec1, vector<int>& vec2) {
  return vec1.back() < vec2.back();
}

class Solution {
 public:
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    int ori_size = intervals.size();
    if (ori_size == 0) return 0;
    if (ori_size == 1) return 0;
    // sort(intervals.begin(), intervals.end(), sortthisvec);
    sort(intervals.begin(), intervals.end(),
         [](vector<int> vec_1, vector<int> vec_2) {
           return vec_1.back() < vec_2.back();
         });
    auto it = intervals.begin() + 1;
    auto it_comp = intervals.begin();
    int cnt = 0;
    while (it != intervals.end()) {
      if ((*it_comp).back() > (*it).front()) {
        ++cnt;
        ++it;
        continue;
      }
      ++it;
      it_comp = it - 1;
    }
    return cnt;
  }
};

int main() {
  vector<vector<int>> a;
  vector<int> m = {1, 2};
  vector<int> n = {2, 3};
  // vector<int> o = {1, 2};
  // vector<int> p = {1, 3};

  a.push_back(m);
  a.push_back(n);
  // a.push_back(o);
  // a.push_back(p);

  Solution sol;
  cout << sol.eraseOverlapIntervals(a) << endl;
}
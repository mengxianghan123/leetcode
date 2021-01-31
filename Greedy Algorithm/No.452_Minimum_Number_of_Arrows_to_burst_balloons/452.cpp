// 这个实现思路与v2一样，但是过程非常冗余笨重

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int findMinArrowShots(vector<vector<int>>& points) {
    int num_arr = 0;
    sort(points.begin(), points.end(),
         [](vector<int> a, vector<int> b) { return a.front() < b.front(); });
    if (points.empty()) return 0;
    auto it = points.begin();
    vector<int> deplicate(2, 0);
    auto it_temp = points.begin() + 1;
    while (it != points.end()) {
      ++num_arr;
      deplicate = *it;
      while (it_temp != points.end()) {
        if ((*it_temp).front() <= deplicate.back()) {
          deplicate.front() = (*it_temp).front();
          deplicate.back() = min(deplicate.back(), (*it_temp).back());
          ++it_temp;
        } else
          break;
      }
      it = it_temp;
      ++it_temp;
    }
    return num_arr;
  }
};
int main() {
  vector<vector<int>> a = {};
  vector<int> o = {10, 16};
  vector<int> p = {2, 8};
  vector<int> q = {1, 6};
  vector<int> r = {7, 12};

  a.push_back(o);
  a.push_back(p);
  a.push_back(q);
  a.push_back(r);

  Solution sol;
  vector<vector<int>> b = {};
  cout << sol.findMinArrowShots(b) << endl;
}
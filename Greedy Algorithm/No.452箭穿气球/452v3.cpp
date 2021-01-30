// 左头降序
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int findMinArrowShots(vector<vector<int>>& points) {
    int num_arr = 1;
    sort(points.begin(), points.end(),
         [](vector<int> a, vector<int> b) { return a.front() > b.front(); });
    if (points.empty()) return 0;
    int target = points[0][0];
    auto next = points.begin() + 1;
    while (next != points.end()) {
      if ((*next).back() < target) {
        ++num_arr;
        target = (*next).front();
      }
      ++next;
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
  cout << sol.findMinArrowShots(a) << endl;
}
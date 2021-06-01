#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if (edges.empty()) return {0};
    if (edges.size() == 1) return {0, 1};
    vector<int> rst;  //存答案,只可能有1个元素或者两个
    vector<unordered_set<int>> neighbor(
        n, unordered_set<int>{});  //存邻接矩阵，我猜这里用unordered_set会快一点
    vector<int> degree(n, 0);  //存度
    int total_num = n;

    //统计
    for (int i = 0; i < edges.size(); ++i) {
      neighbor[edges[i].front()].insert(edges[i].back());
      neighbor[edges[i].back()].insert(edges[i].front());
      ++degree[edges[i].front()];
      ++degree[edges[i].back()];
    }

    queue<int> myqueue;
    for (int i = 0; i < n; ++i) {
      if (degree[i] == 1) {
        myqueue.push(i);
      }
    }

    while (!myqueue.empty()) {
      int qsize = myqueue.size();
      total_num -= qsize;
      while (qsize--) {
        int fnt = myqueue.front();
        myqueue.pop();
        for (int m : neighbor[fnt]) {
          neighbor[m].erase(fnt);
          --degree[m];
          if (degree[m] == 1) {
            myqueue.push(m);
          }
        }
      }
      if (total_num <= 2) {
        int temp = myqueue.size();
        while (temp--) {
          rst.push_back(myqueue.front());
          myqueue.pop();
        }
        return rst;
      }
    }
    return {-1};
  }
};

int main() {
  Solution sol;
  vector<vector<int>> edges = {{3, 0}, {3, 1}, {3, 2}, {3, 4}, {5, 4}};
  int n = 6;
  vector<int> rst = sol.findMinHeightTrees(n, edges);
  for (auto m : rst) {
    cout << m << ' ';
  }
}
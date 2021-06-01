// 对所有点进行bfs后求最小高度（超时）
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int bfs(int i, const int min_depth,
          unordered_map<int, unordered_set<int>> connection) {
    queue<int> myqueue;
    int depth = 0;
    myqueue.push(i);
    while (!myqueue.empty()) {
      int qsize = myqueue.size();
      ++depth;
      if (depth > min_depth) return 999;
      while (qsize-- > 0) {
        int fnt = myqueue.front();
        myqueue.pop();
        unordered_set<int> con_list = connection[fnt];
        for(int m : con_list){
          myqueue.push(m);
          connection[m].erase(fnt);
        }

      }
    }
    return depth;
  }
  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    unordered_map<int, unordered_set<int>> connection;
    for (vector<int> m : edges) {
      connection[m.front()].insert(m.back());
      connection[m.back()].insert(m.front());
    }
    vector<int> rst;
    int min_depth = 999;
    for (int i = 0; i < n; ++i) {
      int depth = bfs(i,  min_depth, connection);
      if (depth < min_depth) {
        min_depth = depth;
        rst.clear();
        rst.push_back(i);
      } else if (depth == min_depth) {
        rst.push_back(i);
      }
    }
    return rst;
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
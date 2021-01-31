// 复杂度稍高
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> partitionLabels(string S) {
    vector<vector<int>> head;
    vector<char> appear;
    for (int m = 0; m < S.size(); ++m) {
      if (find(appear.begin(), appear.end(), S[m]) == appear.end()) {
        vector<int> i = {m, 0};
        head.push_back(i);
        appear.push_back(S[m]);
      }
    }

    for (int m = S.size() - 1; m >= 0; --m) {
      auto idx = find(appear.begin(), appear.end(), S[m]);
      if (idx != appear.end()) {
        head[idx - appear.begin()][1] = m;
        *idx = 'A';
      }
    }

    sort(head.begin(), head.end(),
         [](vector<int> a, vector<int> b) { return a[0] < b[0]; });
    vector<int> rst;
    int flag = head[0][1];
    for (auto it = head.begin() + 1; it != head.end(); ++it) {
      if (it->front() < flag) {
        flag = max(it->back(), flag);
      } else {
        rst.push_back(it->front());
        flag = it->back();
      }
    }
    vector<int> final;
    int cnt = 0;
    for (int i = 0; i <= S.size(); ++i) {
      if (i == S.size() || find(rst.begin(), rst.end(), i) != rst.end()) {
        final.push_back(cnt);
        cnt = 1;
      } else
        ++cnt;
    }
    return final;
  }
};

int main() {
  string s("ababcbacadefegdehijhklij");
  Solution sol;
  vector<int> rst = sol.partitionLabels(s);
  auto beg = rst.begin();
  while (beg != rst.end()) {
    cout << *beg++ << endl;
  }
}
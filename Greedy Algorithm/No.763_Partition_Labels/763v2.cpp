// 官方题解的解法
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> partitionLabels(string S) {
    vector<int> last_idx(26, 0);
    int length = S.size();
    for (int i = 0; i < length; ++i) {
      last_idx[S[i] - 'a'] = i;
    }
    int start = 0, end = 0;
    vector<int> rst;
    for (int i = 0; i < length; ++i) {
      end = max(last_idx[S[i] - 'a'], end);
      if (i == end) {
        rst.push_back(end - start + 1);
        start = end + 1;
      }
    }
    return rst;
  }
};

int main() {
  string s("ababcbacadefegdehijhklij");
  // cout << s.size() << endl;
  Solution sol;
  vector<int> rst = sol.partitionLabels(s);
  auto beg = rst.begin();
  while (beg != rst.end()) {
    cout << *beg++ << endl;
  }
}
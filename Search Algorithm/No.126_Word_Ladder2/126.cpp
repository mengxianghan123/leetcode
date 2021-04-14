// 采用dfs与回溯法，感觉是对的，但是leetcode上超时
// 超时是因为dfs无法判断“最短”，会走很多“弯路”
// 如果涉及“最短”，还是应该考虑bfs
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  void getmin(vector<vector<string>>& ans, int new_minsize) {
    int m = 0;
    while (m < ans.size()) {
      if (ans[m].size() > new_minsize) {
        ans.erase(ans.begin() + m);
      } else
        ++m;
    }
  }
  bool checkdiff(const string& a, const string& b) {
    int cnt = 0;
    for (int i = 0; i < a.size(); ++i) {
      if (a[i] != b[i]) {
        ++cnt;
      }
    }
    if (cnt == 1) return true;
    return false;
  }
  void backtracking(const string& beginword, const string& endword,
                    const vector<string>& wordList, vector<bool>& used,
                    vector<string>& temp, vector<vector<string>>& ans,
                    int& new_minsize) {
    for (int idx = 0; idx < wordList.size(); ++idx) {
      if (temp.size() > new_minsize) return;
      if (used[idx]) continue;
      if (!checkdiff(wordList[idx], beginword)) continue;
      string new_begin = wordList[idx];
      // cout << new_begin << endl;
      if (new_begin == endword) {
        temp.push_back(new_begin);
        new_minsize = min(int(temp.size()), new_minsize);
        ans.push_back(temp);
        temp.pop_back();
        return;
      }
      temp.push_back(new_begin);
      used[idx] = true;
      backtracking(new_begin, endword, wordList, used, temp, ans, new_minsize);
      temp.pop_back();
      used[idx] = false;
    }
  }
  vector<vector<string>> findLadders(string beginWord, string endWord,
                                     vector<string>& wordList) {
    vector<vector<string>> ans;
    vector<bool> used(wordList.size(), false);
    vector<string> temp;
    int new_minsize = 999;
    if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
      return {};
    }
    temp.push_back(beginWord);
    backtracking(beginWord, endWord, wordList, used, temp, ans, new_minsize);
    getmin(ans, new_minsize);
    return ans;
  }
};

int main() {
  Solution sol;
  string beginWord = "hit";
  string endWord = "cog";
  vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
  vector<vector<string>> ans = sol.findLadders(beginWord, endWord, wordList);
  // cout << ans.size() << endl;
  for (auto m : ans) {
    for (auto n : m) {
      cout << n << ' ';
    }
    cout << endl;
  }
}
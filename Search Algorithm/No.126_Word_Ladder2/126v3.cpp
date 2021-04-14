// 在v2版本的基础上，尝试修改了一些逻辑，leetcode上运行超时
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  void dfs(string &beginword, string &endword, vector<string> path,
           unordered_map<string, vector<string>> &neighbor,
           vector<vector<string>> &res) {
    path.push_back(beginword);
    if (beginword == endword) {
      res.push_back(path);
      return;
    }
    for (string m : neighbor[beginword]) {
      dfs(m, endword, path, neighbor, res);
    }
  }
  vector<vector<string>> findLadders(string beginWord, string endWord,
                                     vector<string> &wordList) {
    vector<vector<string>> rst;
    vector<string> path;
    unordered_set<string> wordset(wordList.begin(), wordList.end());
    if (wordset.find(endWord) == wordset.end()) return {};
    queue<string> myqueue;
    myqueue.push(beginWord);
    unordered_map<string, int> depth;
    depth[beginWord] = 1;
    int dep = 1;
    unordered_map<string, vector<string>> neighbor;
    while (!myqueue.empty()) {
      int queue_len = myqueue.size();
      ++dep;
      for (; queue_len != 0; --queue_len) {
        string cur = myqueue.front();
        if (cur == endWord) {
          dfs(beginWord, endWord, path, neighbor, rst);
          for (pair<string, vector<string>> m : neighbor) {
            cout << m.first << " : ";
            for (string n : m.second) {
              cout << n << ' ';
            }
            cout << endl;
          }
          return rst;
        }
        myqueue.pop();
        for (int m = 0; m < cur.size(); ++m) {
          string temp = cur;
          for (char o = 'a'; o <= 'z'; ++o) {
            temp[m] = o;
            if (wordset.find(temp) != wordset.end()) {
              if (depth.find(temp) == depth.end()) {
                myqueue.push(temp);
                depth[temp] = dep;
                neighbor[cur].push_back(temp);
              } else if (depth[temp] == dep) {
                neighbor[cur].push_back(temp);
              }
            }
          }
        }
      }
    }
  }
};

int main() {
  Solution sol;
  // string beginWord = "aaaaaaaaaa";
  string beginWord = "hit";
  // string endWord = "cccccccccc";
  string endWord = "cog";
  // vector<string> wordList = {
  //     "aaaaaaaaaa", "caaaaaaaaa", "cbaaaaaaaa", "daaaaaaaaa", "dbaaaaaaaa",
  //     "eaaaaaaaaa", "ebaaaaaaaa", "faaaaaaaaa", "fbaaaaaaaa", "gaaaaaaaaa",
  //     "gbaaaaaaaa", "haaaaaaaaa", "hbaaaaaaaa", "iaaaaaaaaa", "ibaaaaaaaa",
  //     "jaaaaaaaaa", "jbaaaaaaaa", "kaaaaaaaaa", "kbaaaaaaaa", "laaaaaaaaa",
  //     "lbaaaaaaaa", "maaaaaaaaa", "mbaaaaaaaa", "naaaaaaaaa", "nbaaaaaaaa",
  //     "oaaaaaaaaa", "obaaaaaaaa", "paaaaaaaaa", "pbaaaaaaaa", "qaaaaaaaaa",
  //     "qbaaaaaaaa", "raaaaaaaaa", "rbaaaaaaaa", "saaaaaaaaa", "sbaaaaaaaa",
  //     "taaaaaaaaa", "tbaaaaaaaa", "uaaaaaaaaa", "ubaaaaaaaa", "vaaaaaaaaa",
  //     "vbaaaaaaaa", "waaaaaaaaa", "wbaaaaaaaa", "xaaaaaaaaa", "xbaaaaaaaa",
  //     "yaaaaaaaaa", "ybaaaaaaaa", "zaaaaaaaaa", "zbaaaaaaaa", "bbaaaaaaaa",
  //     "bbcaaaaaaa", "bbcbaaaaaa", "bbdaaaaaaa", "bbdbaaaaaa", "bbeaaaaaaa",
  //     "bbebaaaaaa", "bbfaaaaaaa", "bbfbaaaaaa", "bbgaaaaaaa", "bbgbaaaaaa",
  //     "bbhaaaaaaa", "bbhbaaaaaa", "bbiaaaaaaa", "bbibaaaaaa", "bbjaaaaaaa",
  //     "bbjbaaaaaa", "bbkaaaaaaa", "bbkbaaaaaa", "bblaaaaaaa", "bblbaaaaaa",
  //     "bbmaaaaaaa", "bbmbaaaaaa", "bbnaaaaaaa", "bbnbaaaaaa", "bboaaaaaaa",
  //     "bbobaaaaaa", "bbpaaaaaaa", "bbpbaaaaaa", "bbqaaaaaaa", "bbqbaaaaaa",
  //     "bbraaaaaaa", "bbrbaaaaaa", "bbsaaaaaaa", "bbsbaaaaaa", "bbtaaaaaaa",
  //     "bbtbaaaaaa", "bbuaaaaaaa", "bbubaaaaaa", "bbvaaaaaaa", "bbvbaaaaaa",
  //     "bbwaaaaaaa", "bbwbaaaaaa", "bbxaaaaaaa", "bbxbaaaaaa", "bbyaaaaaaa",
  //     "bbybaaaaaa", "bbzaaaaaaa", "bbzbaaaaaa", "bbbbaaaaaa", "bbbbcaaaaa",
  //     "bbbbcbaaaa", "bbbbdaaaaa", "bbbbdbaaaa", "bbbbeaaaaa", "bbbbebaaaa",
  //     "bbbbfaaaaa", "bbbbfbaaaa", "bbbbgaaaaa", "bbbbgbaaaa", "bbbbhaaaaa",
  //     "bbbbhbaaaa", "bbbbiaaaaa", "bbbbibaaaa", "bbbbjaaaaa", "bbbbjbaaaa",
  //     "bbbbkaaaaa", "bbbbkbaaaa", "bbbblaaaaa", "bbbblbaaaa", "bbbbmaaaaa",
  //     "bbbbmbaaaa", "bbbbnaaaaa", "bbbbnbaaaa", "bbbboaaaaa", "bbbbobaaaa",
  //     "bbbbpaaaaa", "bbbbpbaaaa", "bbbbqaaaaa", "bbbbqbaaaa", "bbbbraaaaa",
  //     "bbbbrbaaaa", "bbbbsaaaaa", "bbbbsbaaaa", "bbbbtaaaaa", "bbbbtbaaaa",
  //     "bbbbuaaaaa", "bbbbubaaaa", "bbbbvaaaaa", "bbbbvbaaaa", "bbbbwaaaaa",
  //     "bbbbwbaaaa", "bbbbxaaaaa", "bbbbxbaaaa", "bbbbyaaaaa", "bbbbybaaaa",
  //     "bbbbzaaaaa", "bbbbzbaaaa", "bbbbbbaaaa", "bbbbbbcaaa", "bbbbbbcbaa",
  //     "bbbbbbdaaa", "bbbbbbdbaa", "bbbbbbeaaa", "bbbbbbebaa", "bbbbbbfaaa",
  //     "bbbbbbfbaa", "bbbbbbgaaa", "bbbbbbgbaa", "bbbbbbhaaa", "bbbbbbhbaa",
  //     "bbbbbbiaaa", "bbbbbbibaa", "bbbbbbjaaa", "bbbbbbjbaa", "bbbbbbkaaa",
  //     "bbbbbbkbaa", "bbbbbblaaa", "bbbbbblbaa", "bbbbbbmaaa", "bbbbbbmbaa",
  //     "bbbbbbnaaa", "bbbbbbnbaa", "bbbbbboaaa", "bbbbbbobaa", "bbbbbbpaaa",
  //     "bbbbbbpbaa", "bbbbbbqaaa", "bbbbbbqbaa", "bbbbbbraaa", "bbbbbbrbaa",
  //     "bbbbbbsaaa", "bbbbbbsbaa", "bbbbbbtaaa", "bbbbbbtbaa", "bbbbbbuaaa",
  //     "bbbbbbubaa", "bbbbbbvaaa", "bbbbbbvbaa", "bbbbbbwaaa", "bbbbbbwbaa",
  //     "bbbbbbxaaa", "bbbbbbxbaa", "bbbbbbyaaa", "bbbbbbybaa", "bbbbbbzaaa",
  //     "bbbbbbzbaa", "bbbbbbbbaa", "bbbbbbbbca", "bbbbbbbbcb", "bbbbbbbbda",
  //     "bbbbbbbbdb", "bbbbbbbbea", "bbbbbbbbeb", "bbbbbbbbfa", "bbbbbbbbfb",
  //     "bbbbbbbbga", "bbbbbbbbgb", "bbbbbbbbha", "bbbbbbbbhb", "bbbbbbbbia",
  //     "bbbbbbbbib", "bbbbbbbbja", "bbbbbbbbjb", "bbbbbbbbka", "bbbbbbbbkb",
  //     "bbbbbbbbla", "bbbbbbbblb", "bbbbbbbbma", "bbbbbbbbmb", "bbbbbbbbna",
  //     "bbbbbbbbnb", "bbbbbbbboa", "bbbbbbbbob", "bbbbbbbbpa", "bbbbbbbbpb",
  //     "bbbbbbbbqa", "bbbbbbbbqb", "bbbbbbbbra", "bbbbbbbbrb", "bbbbbbbbsa",
  //     "bbbbbbbbsb", "bbbbbbbbta", "bbbbbbbbtb", "bbbbbbbbua", "bbbbbbbbub",
  //     "bbbbbbbbva", "bbbbbbbbvb", "bbbbbbbbwa", "bbbbbbbbwb", "bbbbbbbbxa",
  //     "bbbbbbbbxb", "bbbbbbbbya", "bbbbbbbbyb", "bbbbbbbbza", "bbbbbbbbzb",
  //     "bbbbbbbbbb", "aaaaaaaaac", "aaaaaaaacc", "aaaaaaaccc", "aaaaaacccc",
  //     "aaaaaccccc", "aaaacccccc", "aaaccccccc", "aacccccccc", "accccccccc",
  //     "cccccccccc"};
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
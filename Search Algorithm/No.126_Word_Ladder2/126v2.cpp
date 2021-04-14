// 题解网址：https://leetcode-cn.com/problems/word-ladder-ii/solution/zhe-ti-you-xie-nan-bie-ren-de-dai-ma-zuo-xia-zhu-s/
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
  void dfs(string &beginword, string &curr, vector<string> path,
           unordered_map<string, vector<string>> &neighbor,
           vector<vector<string>> &res) {
    if (curr == beginword) {
      //到达了迭代终点
      path.push_back(curr);
      reverse(path.begin(), path.end());
      res.push_back(path);
      return;
    }
    //这里的path记录状态，这是c++的一个技巧，状态使用传值，则每个节点都是一个全新的状态，无需状态重置。
    path.push_back(curr);
    for (auto word : neighbor[curr]) {
      //对于邻接节点
      dfs(beginword, word, path, neighbor, res);
    }
  }
  vector<vector<string>> findLadders(string beginWord, string endWord,
                                     vector<string> &wordList) {
    //两个关键的数据结构，每个节点的邻接节点（每个节点的下一层节点，只相差一个字符的）
    //存储每个节点所在的深度
    /*
    1)先使用BFS"建图"，在搜索过程中记录信息
    */
    vector<vector<string>> res;
    vector<string> path;
    if (std::find(wordList.begin(), wordList.end(), endWord) == wordList.end())
      return res;

    unordered_map<string, int> depth;
    unordered_map<string, vector<string>> neighbor;
    // convert vector into hashset,or use boolean matrix
    unordered_set<string> wordSet(wordList.begin(), wordList.end());
    // vector<int> visited(wordList.size(),0);

    // BFS to get words neighbors(only next layers neighbors)
    depth[beginWord] = 1;
    queue<string> Q;
    Q.push(beginWord);
    //从begin到end建图
    while (!Q.empty()) {
      string curr = Q.front();
      Q.pop();
      for (int i = 0; i < curr.size(); ++i) {
        string temp = curr;
        for (char c = 'a'; c <= 'z'; ++c) {
          temp[i] = c;
          if (wordSet.count(temp)) {
            //如果修改的这个temp是被包含的,再字典里面
            if (depth.count(temp) == 0) {
              //这个temp还没被添加进neighbor
              Q.push(temp);
              depth[temp] = depth[curr] + 1;  // update depth map
              neighbor[temp].push_back(curr);
            } else if (depth[temp] == depth[curr] + 1) {
              neighbor[temp].push_back(curr);
            }
          }
        }
      }
    }
    dfs(beginWord, endWord, path, neighbor, res);
    for (pair<string, vector<string>> m : neighbor) {
      cout << m.first << " : ";
      for (string n : m.second) {
        cout << n << ' ';
      }
      cout << endl;
    }
    return res;
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
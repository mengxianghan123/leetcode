#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  string frequencySort(string s) {
    unordered_map<char, int> mymap;
    for (char i : s) {
      ++mymap[i];
    }
    vector<pair<char, int>> temp;
    for (pair<char, int> i : mymap) {
      temp.push_back(i);
    }
    sort(temp.begin(), temp.end(),
         [](const pair<char, int>& a, const pair<char, int>& b) {
           return a.second > b.second;
         });
    string rst;
    for (pair<char, int> i : temp) {
      for (int cnt = 0; cnt < i.second; ++cnt) rst += i.first;
    }
    return rst;
  }
};

int main() {
  Solution sol;
  string s = "Aabb";
  string rst = sol.frequencySort(s);
  cout << rst << endl;
}
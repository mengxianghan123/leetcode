#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  public:
  int findContentChildren(vector<int> &g, vector<int> &s)
  {
    int cnt = 0;
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    for (auto it = g.begin(); it != g.end(); ++it)
    {
      int cur_g = *it;
      for (auto it_s = s.begin(); it_s != s.end(); ++it_s)
      {
        if (*it <= *it_s)
        {
          cnt++;
          s.erase(it_s, it_s + 1);
          break;
        }
      }
    }
    return cnt;
  }
};
int main()
{
  vector<int> g = {1, 2};
  vector<int> s = {1, 2, 3};
  Solution solution;

  int cnt = solution.findContentChildren(g, s);
  cout << cnt << endl;
}
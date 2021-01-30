#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
 public:
  int candy(vector<int>& ratings) {
    vector<int> rst(ratings.size(), 1);
    auto it = ratings.begin();
    while (it != ratings.end() - 1) {
      if (*it < *(it + 1))
        rst[it + 1 - ratings.begin()] = rst[it - ratings.begin()] + 1;
      ++it;
    }
    // for (auto m : rst){cout<<m<<' ';}
    it = ratings.end() - 1;
    while (it != ratings.begin()) {
      if ((*(it - 1) > *it) &&
          (rst[it - ratings.begin()] >= rst[it - ratings.begin() - 1]))
        rst[it - 1 - ratings.begin()] = rst[it - ratings.begin()] + 1;
      --it;
    }
    // int sum = 0;
    // for (auto i : rst) {
    //   sum += i;
    // }
    // return sum;
    return accumulate(rst.begin(), rst.end(),
                      0);  // numeric库中的累加函数。第3个参数为累加的初始值
  }
};

int main() {
  Solution sol;
  vector<int> rating = {1, 2, 2};
  cout << sol.candy(rating) << endl;
}
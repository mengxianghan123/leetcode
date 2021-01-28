#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    if (flowerbed.size() == 1) {
      if (flowerbed[0] == 0 && n <= 1)
        return true;
      else if (flowerbed[0] == 0 && n > 1)
        return false;
      else if (flowerbed[0] == 1 && n == 0)
        return true;
      else
        return false;
    }
    if (flowerbed.size() == 2) {
      if (flowerbed[0] == 0 && flowerbed[1] == 0) {
        if (n <= 1)
          return true;
        else
          return false;
      } else {
        if (n == 0)
          return true;
        else
          return false;
      }
    }
    int cnt = 0;
    if (flowerbed[0] == 0 && flowerbed[1] == 0) {
      ++cnt;
      flowerbed[0] = 1;
    }
    if (flowerbed[flowerbed.size() - 1] == 0 &&
        flowerbed[flowerbed.size() - 2] == 0) {
      ++cnt;
      flowerbed[flowerbed.size() - 1] = 1;
    }
    for (auto it = flowerbed.begin() + 1; it < flowerbed.end() - 1; ++it) {
      if (*(it - 1) == 0 && *it == 0 && *(it + 1) == 0) {
        ++cnt;
        it += 1;
        continue;
      }
    }
    if (cnt >= n)
      return true;
    else
      return false;
  }
};

int main() {
  Solution sol;
  vector<int> a = {1, 0, 0, 0, 1};
  int b = 2;
  cout << sol.canPlaceFlowers(a, b) << endl;
}
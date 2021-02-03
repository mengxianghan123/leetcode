// 练习一下二分法
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    for (int i = 0; i < numbers.size(); ++i) {
      auto id = binary_search(numbers.begin() + i + 1, numbers.end(),
                              target - numbers[i]);
      if (id != numbers.end()) return {i + 1, int(id - numbers.begin() + 1)};
    }
    return {0, 0};
  }
  vector<int>::iterator binary_search(vector<int>::iterator beg,
                                      vector<int>::iterator end, int target) {
    auto b = beg, e = end;
    while (b < e) {
      auto mid = (e - b) / 2 + b;
      if (*mid == target) {
        return mid;
      } else if (*mid < target)
        b = mid + 1;
      else
        e = mid;
    }
    return end;
  }
};

int main() {
  vector<int> numbers = {2, 7, 11, 15};
  int target = 9;
  Solution sol;
  vector<int> rst = sol.twoSum(numbers, target);
  cout << rst[0] << ' ' << rst[1] << endl;
}
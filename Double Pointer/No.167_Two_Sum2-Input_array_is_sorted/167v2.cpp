// 双指针法
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    int start = 0, end = numbers.size() - 1;
    while (numbers[start] + numbers[end] != target) {
      if (numbers[start] + numbers[end] < target) {
        ++start;
      } else {
        --end;
      }
    }
    vector<int> rst;
    rst.push_back(start + 1);
    rst.push_back(end + 1);
    return rst;
  }
};

int main() {
  vector<int> numbers = {2, 3, 4};
  int target = 6;
  Solution sol;
  vector<int> rst = sol.twoSum(numbers, target);
  cout << rst[0] << ' ' << rst[1] << endl;
}
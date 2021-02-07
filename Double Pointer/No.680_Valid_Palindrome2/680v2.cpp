// 只用双指针，逻辑有点小复杂
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool validPalindrome(string s) {
    if (s.empty()) return true;
    int l = 0, r = s.size() - 1;
    while (l <= r) {
      if (s[l] == s[r]) {
        ++l;
        --r;
      } else {
        int templ = l, tempr = r;
        r = tempr - 1;
        while (l <= r) {
          if (s[l] == s[r]) {
            ++l;
            --r;
          }
					else{
						l = templ + 1;
						r = tempr;
						while(l<=r){
							if(s[l]==s[r]){
								++l;
								--r;
							}
							else return false;
						}
					}
        }
				return true;
      }
    }
    return true;
  }
};

int main() {
  string a = "ebcbbececabbacecbbcbe";
  Solution sol;
  cout << sol.validPalindrome(a) << endl;
}
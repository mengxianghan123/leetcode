// 这是按照身高从低到高排序的
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort(people.begin(), people.end(), [](vector<int>& a, vector<int>& b) {
      return (a[0]<b[0])||(a[0]==b[0] && a[1] > b[1]);
    });
		vector<vector<int>> rst(people.size());
		for(auto i : people){
			int cnt = 0;
			for(auto m =rst.begin();m!=rst.end();++m){
				if(m->empty()) ++cnt;
				if(cnt==i[1]+1) {
					*m = i;
					break;
				}
			}
		}
		return rst;
  }
};

int main() {
	vector<vector<int>> people;
	vector<int> a = {7,0};
	vector<int> b = {4,4};
	vector<int> c = {7,1};
	vector<int> d = {5,0};
	vector<int> e = {6,1};
	vector<int> f = {5,2};

	people.push_back(a);
	people.push_back(b);
	people.push_back(c);
	people.push_back(d);
	people.push_back(e);
	people.push_back(f);

	Solution sol;
	
	vector<vector<int>>rst = sol.reconstructQueue(people);
	for(auto i : rst){
		cout<<i[0]<<' '<<i[1]<<endl;
	}

}
## 1.题目
给定一个字符串 s ，找出至多包含 k 个不同字符的最长子串 T。  

示例 1:  
输入: s = "eceba", k = 2  
输出: 3  
解释: 则 T 为 "ece"，所以长度为 3。  

示例 2:  
输入: s = "aa", k = 1  
输出: 2  
解释: 则 T 为 "aa"，所以长度为 2。  

---

## 2.分析
这道题其实也是非常典型的滑动窗的题目，右指针增大区间，左指针缩小区间，右指针移动到刚刚好不满足题目条件，再由左指针移动到刚刚好满足题目条件，与之前出现的滑动窗口的题目实现思路完全一致。  
落实到具体代码实现，感觉也是成套路的，如果自己随意发挥，写出来的逻辑往往复杂且易错，还是需要去积累正确的写法。  
使用的数据结构方面，我采用了比较熟悉的128维vector向量，写出来的时间和空间复杂度都很高，换用了unordered_map，复杂度显著下降。  

---

## 3.其它
先贴出[大神的解法](https://leetcode-cn.com/problems/longest-substring-with-at-most-k-distinct-characters/solution/ji-zhi-jian-dan-by-sonp-2/)：  
```
class Solution {
public:

    int lengthOfLongestSubstringKDistinct(string s, int k) {
    int n = s.size();
	unordered_map<char, int> count;
	int j = 0, res = 0, cnt=0;
	for(int i=0; i<n; ++i){
		if(count[s[i]]++==0) ++cnt;
		while(cnt>k){
			if(--count[s[j++]]==0) --cnt;
		}
		res = max(res, i-j+1);
	}
	return res;
    }
};
```  
关于[unordered_map的使用](https://blog.csdn.net/hk2291976/article/details/51037095)
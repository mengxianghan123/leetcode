## 1.题目
给定一个字符串和一个字符串字典，找到字典里面最长的字符串，该字符串可以通过删除给定字符串的某些字符来得到。如果答案不止一个，返回长度最长且字典顺序最小的字符串。如果答案不存在，则返回空字符串。  

示例 1:  
输入:  
s = "abpcplea", d = ["ale","apple","monkey","plea"]  
输出:   
"apple"  

示例 2:  
输入:  
s = "abpcplea", d = ["a","b","c"]  
输出:   
"a"  

说明:  
所有输入的字符串只包含小写字母。  
字典的大小不会超过 1000。  
所有输入的字符串长度不会超过 1000。  

---

## 2.分析
这个题目感觉思路不是很复杂。  
题目需要找到满足“可以通过删除给定字符串的某些字符来得到”的最长的字符串。因此，我首先想对字典里的字符串进行排序，排序规则是长度更长的优先，等长条件下，更小的优先。  
排序过后，依次遍历字典中的字符串就可以找到满足条件且最长的字符串了。  
判断一个字符串是否满足条件，启用双指针。如果两字母相等，两指针都后移；如果两字母不等，说明字符串s里的该字符要被删，继续检查s后面的字符，也就是移动指向s字符串的指针，另一指针不动。  
完。  
## 1.题目
给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。  
注意：如果 s 中存在这样的子串，我们保证它是唯一的答案。  

示例 1：  
输入：s = "ADOBECODEBANC", t = "ABC"  
输出："BANC"  

示例 2：  
输入：s = "a", t = "a"  
输出："a"  

提示：  
1 <= s.length, t.length <= 105  
s 和 t 由英文字母组成  

进阶：你能设计一个在 o(n) 时间内解决此问题的算法吗？  

---

## 2.分析
Emmmm感觉这个题真的挺麻烦的，但是传递出的思想确实双指针中最基本的思想。  
左右指针动态的扫过整个序列，右指针移动是为了增加区间长度，去寻找满足条件的区间，左指针移动是为了减少区间长度，使区间在满足条件时又尽量小。  
在这道题的背景下就是，不断右移右指针，直到区间中包含了t的全部字母，此时不断右移左指针，直到刚好不能全部包含t的字母，记录此时的区间长度和起始点。再继续右移右指针...这里有个问题，左指针应该移动到什么位置？如果左指针移动完，区间仍旧包含全部t的字母，那么此时右指针就没有动机继续右移了，所以这里左指针要刚好不能全部包含t的字母。我不清楚这是不是个双指针的常识，但是可以积累一下。  
那么，这个过程中，我们会需要判断，区间中是否包含了t的全部字母。题解中多数办法都是用一个可以包含全部字母的向量，向量的每个位置对应一个字母，存储的数对应还需要多少个该字母/有多少个该字母。这样，可以通过判断向量是否为全零/大于t的每个字母的数量来判断条件是否满足。如果嫌遍历向量麻烦，还可以再统计一个cnt变量来存储满足条件/不满足条件的字母个数，判断起来会更方便一些。  
感觉表达也不是很清楚，看别人写的代码有时候也更糊涂，还是得自己动手尝试一次，自己写出来之后，一切都明朗了。  

---

## 3.其它
附一个[C++string类常用方法](https://blog.csdn.net/qq_37954088/article/details/82286530)
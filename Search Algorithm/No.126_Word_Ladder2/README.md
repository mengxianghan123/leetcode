## 1.题目
给定两个单词（beginWord 和 endWord）和一个字典 wordList，找出所有从 beginWord 到 endWord 的最短转换序列。转换需遵循如下规则：  
每次转换只能改变一个字母。  
转换后得到的单词必须是字典中的单词。  

说明:  
如果不存在这样的转换序列，返回一个空列表。  
所有单词具有相同的长度。  
所有单词只由小写字母组成。  
字典中不存在重复的单词。  
你可以假设 beginWord 和 endWord 是非空的，且二者不相同。  

示例 1:  
```
输入:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

输出:
[
  ["hit","hot","dot","dog","cog"],
  ["hit","hot","lot","log","cog"]
]
```  

示例 2:  
```
输入:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

输出: []

解释: endWord "cog" 不在字典中，所以不存在符合要求的转换序列。
```  

---

## 2.分析
此题相当困难，到现在为止，我也只理解了一个题解。[此题解](https://leetcode-cn.com/problems/word-ladder-ii/solution/zhe-ti-you-xie-nan-bie-ren-de-dai-ma-zuo-xia-zhu-s/)讲解的还是非常清晰的，学习后感觉十分受用。  
在理解了此解法后，我做了几次尝试，发现了一些问题，总结一下：  
&emsp;（1）DFS不能解决“最短”问题，遇到“最短”要考虑BFS。但BFS不能记录下路径，需要记录路径要考虑DFS。  
&emsp;（2）大多题解在寻找wordlist中所有与curr字符串只差一个字符的字符串时，采取的办法都是：遍历curr字符串的每一位，再遍历26个字母，逐位逐字母替换，再去wordlist中查找。起初我还以为这是种复杂度高的办法，换用了一种：遍历wordlist所有字符串，逐字母比较字符串与curr，判断是否只差一个字符。殊不知我这种方法反而复杂度高。由于采用unoordered_set存储wordlist，搜索复杂度为o(1),因此题解的方法复杂度为o(26n),而我的办法复杂度为o(mn)，严重依赖wordlist长度，没有利用好哈希表方便查找的特点，在遇到wordlist非常大的情况时，直接超时。  
&emsp;（3）我在v3版本还将题解的逆邻接改为了邻接，然后最后dfs时从begin搜到end，也超时了。经过思考后，我发现，在bfs时，有很多支路其实可能会是死路，最终通往不了endword，中途结束。那么如果我从begin开始dfs，就必定会搜索到这样的路径。但是由于bfs时是从begin到end，因此如果从end开始搜索路径必定可以到begin，不会出现死路（这里还挺神奇的）。因此最终dfs时一定要从end到begin，也因此在记录neighbor时要注意记录每个节点的前项neighbor而不是后项neighbor，这真的是一个精巧的设计。  

此题还有很多其它解法，以及双向BFS解法，留到以后再学习吧。  
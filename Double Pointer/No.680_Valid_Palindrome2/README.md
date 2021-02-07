## 1.题目
给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。  

示例 1:  
输入: "aba"  
输出: True  

示例 2:  
输入: "abca"  
输出: True  
解释: 你可以删除c字符。  

注意:  
字符串只包含从 a-z 的小写字母。字符串的最大长度是50000。  

---

## 2.分析
这个题采用双指针，左指针从最左端往右遍历，右指针从最右端往左遍历，如果两指针指向元素相等，移动左右指针。  
问题出在左右两指针不等时，我最初的想法为，如果左指针右侧的字母与右指针对应的字母相等，则左指针右移；如果右指针左侧的字母与左指针对应的字母相等，则右指针左移。剩余的字符串继续遍历，不许出现两指针对应元素不等的情况。  
而后发现，这样的思路存在问题，例如字符串为："ebcbbececabbacecbbcbe"。此时上面提到的两种情况都满足，应该两种情况都去尝试，而非只尝试第一种情况。  
对此，我想到的两种解决方式：  
&emsp;1）递归求解。这和官方题解思路相同，写一个函数负责查字符串是否为回文字符串，然后主调函数返回两种情况的结果取或。（感觉说不太清楚，一看代码就能懂了）  
&emsp;2）写个复杂逻辑。先查一种情况，如果不满足回文，再查另一种情况，如果不满足回文，返回false。这个感觉比较啰嗦，并且可扩展性也不好。

---

## 3.其它
在官方题解的评论区看到一个非常精简而漂亮的代码，用的是递归思路，这里[引用一下](https://leetcode-cn.com/problems/valid-palindrome-ii/solution/yan-zheng-hui-wen-zi-fu-chuan-ii-by-leetcode-solut/)。  
```
class Solution {
public:
    bool palindrome(const std::string& s, int i, int j)
    {
        for ( ; i < j && s[i] == s[j]; ++i, --j);
        return i >= j;
    }

    bool validPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        for ( ; i < j && s[i] == s[j]; ++i, --j);        
        return palindrome(s, i, j - 1) || palindrome(s, i + 1, j);
    }
};
```
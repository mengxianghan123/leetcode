## 1.题目  
实现 int sqrt(int x) 函数。  
计算并返回 x 的平方根，其中 x 是非负整数。  
由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。  

示例 1:  
输入: 4  
输出: 2  

示例 2:  
输入: 8  
输出: 2  
说明: 8 的平方根是 2.82842...,由于返回类型是整数，小数部分将被舍去。  

---

## 2.分析  
只有整数部分的平方根，可以换一种方式理解，就是此数的平方小于等于x，但是此数+1的平方大于x。  
根据这句话，套用二分查找的模板，不难写出此题的答案。  
但是此题用二分查找还有别的思路，可以将题目理解成：查找平方小于等于x的最小整数。因此，可以修改二分查找的写法，这里[引用官方题解的做法：](https://leetcode-cn.com/problems/sqrtx/solution/x-de-ping-fang-gen-by-leetcode-solution/)  
```
class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x, ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if ((long long)mid * mid <= x) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};
```  
此外，此题还可以用牛顿法进行迭代求解，具体思路和推导官方题解写的非常清楚，值得参考。
## 1.题目
给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。  

示例 1：  
```
输入：nums = [1,1,2]
输出：
[[1,1,2],
 [1,2,1],
 [2,1,1]]
```

示例 2：  
```
输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
```

提示：  
1 <= nums.length <= 8  
-10 <= nums[i] <= 10  

---

## 2.分析
对于重复元素，官方题解告诉我们：**不让重复元素出现在同样一个位置上，即可避免最后给出排列的重复**。  
这个思路有点贪婪算法的意思，还挺神奇的。  
另外，要注意，正常情况下的回溯：  
```
for(所有分支)
尝试一条分支；递归；回溯；
```
对于特殊情况（比如path满了需要return），**不要忘记在return前进行回溯** ，这个错误已经犯了很多次了。  

另外，[官方题解](https://leetcode-cn.com/problems/permutations-ii/solution/quan-pai-lie-ii-by-leetcode-solution/)写法很巧妙，摘录一下：  
```
class Solution {
    vector<int> vis;

public:
    void backtrack(vector<int>& nums, vector<vector<int>>& ans, int idx, vector<int>& perm) {
        if (idx == nums.size()) {
            ans.emplace_back(perm);
            return;
        }
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (vis[i] || (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1])) {
                continue;
            }
            perm.emplace_back(nums[i]);
            vis[i] = 1;
            backtrack(nums, ans, idx + 1, perm);
            vis[i] = 0;
            perm.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> perm;
        vis.resize(nums.size());
        sort(nums.begin(), nums.end());
        backtrack(nums, ans, 0, perm);
        return ans;
    }
};
```
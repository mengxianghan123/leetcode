## 1.题目
n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。  
给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。  
每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。  

示例1：  
```
输入：n = 4
输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
解释：如上图所示，4 皇后问题存在两个不同的解法。
```  

示例2：  
```
输入：n = 1
输出：[["Q"]]
```

---

## 2.思路
如果熟悉了回溯法，感觉此题的思路并不是非常复杂。  
当我每给一个新皇后选定位置a，就需要在棋盘中排除一些位置，这些位置是需要记录下来的。而后递归棋盘其余的位置。当递归返回，需要选择一个新位置b，此时就需要撤销由于占据位置a占据的其它位置，即回溯。  
具体实现时，我用visited矩阵来记录被占据的位置，每次安置一个新皇后时，就从已有皇后的下一行棋盘开始选择，如果这一行都没有满足安置条件的位置，递归返回。  

我这边解法时间复杂度较高，[moreality](https://leetcode-cn.com/problems/n-queens/solution/51-n-huang-hou-hui-su-an-xing-bian-li-du-bg8h/)提供的解法思路相似但是写法更加规范，复杂度也较低：  
```
class Solution {
public:
    vector<bool> column, diag_up, diag_down;
    vector<vector<string>> ans;
    vector<vector<string>> solveNQueens(int n) {
        if (n == 0) return ans;
        // init the mark matrix
        column.resize(n, false); diag_up.resize(2 * n - 1, false); diag_down.resize(2 * n - 1, false);
        vector<string> board(n, string(n, '.'));
        dfs(board, 0, n);
        return ans;
    }
    void dfs(vector<string> board, int row, int n) {
        if (row == n) {
            ans.push_back(board);
            return;
        }
        for (int col = 0; col < n; ++col) {
            //  has queen in column and two diags.
            int down = n - row + col - 1, up = row + col;
            if (column[col] || diag_down[down] || diag_up[up]) {
                continue;
            }
            // mark
            board[row][col] = 'Q';
            column[col] = diag_down[down] = diag_up[up] = true;
            // dfs
            dfs(board, row + 1, n);
            // revoke marks
            board[row][col] = '.';
            column[col] = diag_down[down] = diag_up[up] = false;
        }
    }
};

```
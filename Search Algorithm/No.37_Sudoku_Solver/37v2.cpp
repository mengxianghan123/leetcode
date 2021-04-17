// 这是官方题解下面的一个解法。https://leetcode-cn.com/u/yang-shuai-n/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        for (auto i = 0; i < board.size(); ++i) {
            for (auto j = 0; j < board[i].size(); ++j) {
                char c = board[i][j];
                if (c == '.') {
                    mSpace.emplace_back(i, j);
                }
                else {
                    mRow[i][c - '1'] = true;
                    mCol[j][c - '1'] = true;
                    mSquared[i / 3 * 3 + j / 3][c - '1'] = true;
                }
            }
        }
        Dfs(board, 0);
    }

    bool Dfs(vector<vector<char>>& board, int index) {
        if (index == mSpace.size()) {
            return true;
        }

        auto row = mSpace[index].first;
        auto col = mSpace[index].second;
        for (auto c = '1'; c <= '9'; ++c) {
            auto num = c - '1';
            if (!mRow[row][num] && !mCol[col][num] && !mSquared[row / 3 * 3 + col / 3][num]) {
                board[row][col] = c;
                mRow[row][num] = true;
                mCol[col][num] = true;
                mSquared[row / 3 * 3 + col / 3][num] = true;
                if (Dfs(board, index + 1)) {
                    return true;
                }
                mRow[row][num] = false;
                mCol[col][num] = false;
                mSquared[row / 3 * 3 + col / 3][num] = false;
            }
        }
        return false;
    }

private:
    bool mCol[9][9];
    bool mRow[9][9];
    bool mSquared[9][9];
    vector<pair<int, int>> mSpace;
};
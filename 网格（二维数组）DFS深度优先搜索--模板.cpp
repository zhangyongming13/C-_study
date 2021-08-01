#include <vector>

using namespace std;

class Solution {
    static bool IsInArea(int row, int col, const vector<vector<int>> &grid)
    {
        // 返回当前是否已经超出范围了
        return (row >= 0) && (col >= 0) && (row < grid.size()) && (col < grid[0].size());
    }

    void Dfs(int row, int col, vector<vector<int>> &grid)
    {
        // 超出范围了，不进行遍历
        if (!IsInArea(row, col, grid)) {
            return;
        }

        // 将这个点标记为已遍历
        grid[row][col] = 2;

        // 继续遍历上下左右结点
        Dfs(row - 1, col, grid);
        Dfs(row + 1, col, grid);
        Dfs(row, col - 1, grid);
        Dfs(row, col + 1, grid);
    }
};

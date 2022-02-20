#include <vector>
#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    int shortestBridge(vector<vector<int>> &grid)
    {
        rowSize = static_cast<int>(grid.size());
        colSize = static_cast<int>(grid[0].size());
        bool breakFlag = false;
        // 先使用深度优先算法，找到第一个岛，寻找的图中把1变成2表示已遍历
        for (int i = 0; i < rowSize; ++i) {
            for (int j = 0; j < colSize; ++j) {
                if (grid[i][j] == 1) {
                    Dfs(grid, i, j);
                    breakFlag = true;
                    break;
                }
            }

            if (breakFlag) {
                break;
            }
        }

        // BFS广度优先遍历找到对应的第二个岛
        int level = 0;
        vector<int> dict = { 1, 0, -1, 0, 1 };
        while (!queueIndex.empty()) {
            int queueIndexSize = static_cast<int>(queueIndex.size());
            level++;
            while (queueIndexSize > 0) {
                vector<int> currVec = queueIndex.front();
                queueIndex.pop();
                for (int i = 0; i < (dict.size() - 1); ++i) {
                    if (GetValue(grid, currVec[0] + dict[i], currVec[1] + dict[i + 1]) == 1) {
                        return level - 1;
                    }
                }

                queueIndexSize--;
            }
        }

        return 0;
    }

private:
    int GetValue(vector<vector<int>> &grid, int i, int j)
    {
        if (!IsInArea(i, j)) {
            return -1;
        }

        if (grid[i][j] == 2) {
            return -1;
        }

        if (grid[i][j] == 1) {
            return 1;
        }

        if (grid[i][j] == 0) {
            grid[i][j] = 2;
            queueIndex.push({ i, j });
            return 0;
        }

        return -1;
    }

    void Dfs(vector<vector<int>> &grid, int i, int j)
    {
        if (!IsInArea(i, j)) {
            return;
        }

        if (grid[i][j] != 1) {
            return;
        }

        queueIndex.push({ i, j });
        grid[i][j] = 2;

        Dfs(grid, i - 1, j);
        Dfs(grid, i + 1, j);
        Dfs(grid, i, j + 1);
        Dfs(grid, i, j - 1);
    }

    bool IsInArea(int i, int j) const
    {
        return (i >= 0) && (i < rowSize) && (j >= 0) && (j < colSize);
    }

private:
    queue<vector<int>> queueIndex;
    int rowSize = 0;
    int colSize = 0;
};

int main()
{
    vector<vector<int>> grid = {{0,1,0},{0,0,0},{0,0,1}};
    Solution solution;
    cout << solution.shortestBridge(grid) << endl;

    return 0;
}

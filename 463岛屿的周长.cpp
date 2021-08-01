#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    Solution()
    {
        gridRow = 0;
        gridCol = 0;
    }

    bool IsInArea(int i, int j) const
    {
        return (i >= 0) && (j >= 0) && (i < gridRow) && (j < gridCol);
    }

    int Dfs(int i, int j, vector<vector<int>> &grid)
    {
        // 当超出边界之后说明遇到了一条边
        if (!IsInArea(i, j)) {
            return 1;
        }

        // 遇到0即海的时候也是一条边
        if (grid[i][j] == 0) {
            return 1;
        }

        // 已经被遍历过的就不重复计算了
        if (grid[i][j] == 2) {
            return 0;
        }

        grid[i][j] = 2;

        return Dfs(i - 1, j, grid) + Dfs(i + 1, j, grid) + Dfs(i, j - 1, grid) + Dfs(i, j + 1, grid);
    }

    int islandPerimeter(vector<vector<int>> &grid)
    {
        int islandCir = 0;
        gridRow = static_cast<int>(grid.size());
        gridCol = static_cast<int>(grid[0].size());

        for (int i = 0; i < gridRow; ++i) {
            for (int j = 0; j < gridCol; ++j) {
                if (grid[i][j] == 1) {
                    islandCir = Dfs(i, j, grid);
                    return islandCir;
                }
            }
        }

        return islandCir;
    }

private:
    int gridRow;
    int gridCol;
};

int main()
{
    vector<vector<int>> grid;
    vector<int> row1 = {0,1,0,0};
    vector<int> row2 = {1,1,1,0};
    vector<int> row3 = {0,1,0,0};
    vector<int> row4 = {1,1,0,0};
    grid.emplace_back(row1);
    grid.emplace_back(row2);
    grid.emplace_back(row3);
    grid.emplace_back(row4);

    Solution solution;
    int result = solution.islandPerimeter(grid);
    cout << "The perimeterperimeter of island is " << result << endl;
}

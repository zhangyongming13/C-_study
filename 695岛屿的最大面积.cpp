#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    Solution()
    {
        gridCol = 0;
        gridRow = 0;
    }

    bool IsInArea(int i, int j) const
    {
        return (i >= 0) && (j >= 0) && (i < gridRow) && (j < gridCol);
    }

    void Dfs(int i, int j, int &area, vector<vector<int>>& grid)
    {
        if (!IsInArea(i, j)) {
            return;
        }

        if (grid[i][j] != 1) {
            return;
        }

        area++;
        grid[i][j] = 2;

        Dfs(i - 1, j, area, grid);
        Dfs(i + 1, j, area, grid);
        Dfs(i, j - 1, area, grid);
        Dfs(i, j + 1, area, grid);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        gridRow = static_cast<int>(grid.size());
        gridCol = static_cast<int>(grid[0].size());

        int maxArea = 0;
        for (int i = 0; i < gridRow; ++i) {
            for (int j = 0; j < gridCol; ++j) {
                if (grid[i][j] == 1) {
                    int tmpArea = 0;
                    Dfs(i, j, tmpArea, grid);

                    maxArea = max(maxArea, tmpArea);
                }
            }
        }

        return maxArea;
    }

private:
    int gridRow;
    int gridCol;
};

int main()
{
    vector<vector<int>> grid;
    vector<int> row1 = {0,0,1,0,0,0,0,1,0,0,0,0,0};
    vector<int> row2 = {0,0,0,0,0,0,0,1,1,1,0,0,0};
    vector<int> row3 = {0,1,1,0,1,0,0,0,0,0,0,0,0};
    vector<int> row4 = {0,1,0,0,1,1,0,0,1,0,1,0,0};
    vector<int> row5 = {0,1,0,0,1,1,0,0,1,1,1,0,0};
    vector<int> row6 = {0,0,0,0,0,0,0,0,0,0,1,0,0};
    vector<int> row7 = {0,0,0,0,0,0,0,1,1,1,0,0,0};
    vector<int> row8 = {0,0,0,0,0,0,0,1,1,0,0,0,0};
    grid.emplace_back(row1);
    grid.emplace_back(row2);
    grid.emplace_back(row3);
    grid.emplace_back(row4);
    grid.emplace_back(row5);
    grid.emplace_back(row6);
    grid.emplace_back(row7);
    grid.emplace_back(row8);

    Solution solution;
    int result = solution.maxAreaOfIsland(grid);
    cout << "The max area of island is " << result << endl;
}

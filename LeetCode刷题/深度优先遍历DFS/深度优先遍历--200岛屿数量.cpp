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

    void Dfs(int i, int j, vector<vector<char>>& grid) const
    {
        if (!IsInArea(i, j)) {
            return;
        }

        if ((grid[i][j] == '0') || (grid[i][j] == '2')) {
            return;
        }

        grid[i][j] = '2';

        Dfs(i - 1, j, grid);
        Dfs(i + 1, j, grid);
        Dfs(i, j - 1, grid);
        Dfs(i, j + 1, grid);
    }

    int numIslands(vector<vector<char>>& grid)
    {
        int result = 0;
        gridRow = static_cast<int>(grid.size());
        gridCol = static_cast<int>(grid[0].size());

        for (int i = 0; i < gridRow; ++i) {
            for (int j = 0; j < gridCol; ++j) {
                if (grid[i][j] == '1') {
                    result++;
                    Dfs(i, j, grid);
                }
            }
        }

        return result;
    }

private:
    int gridRow;
    int gridCol;
};

int main()
{
    vector<vector<char>> grid;
    vector<char> row1 = {'1','1','0','0','0'};
    vector<char> row2 = {'1','1','0','0','0'};
    vector<char> row3 = {'0','0','1','0','0'};
    vector<char> row4 = {'0','0','0','1','1'};
    grid.emplace_back(row1);
    grid.emplace_back(row2);
    grid.emplace_back(row3);
    grid.emplace_back(row4);

    Solution solution;
    int result = solution.numIslands(grid);
    cout << "Island number is " << result << endl;
}

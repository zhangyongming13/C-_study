#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        row = static_cast<int>(grid.size());
        col = static_cast<int>(grid[0].size());
        int result = 0;

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if ((grid[i][j] == 1) && IsEdge(i, j) ) {
                    Dfs(grid, i, j);
                }
            }
        }

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == 1) {
                    result++;
                }
            }
        }

        return result;
    }

private:
    bool IsEdge(int i, int j) const
    {
        return ((i == 0) || (i == (row - 1)) || (j == 0) || (j == (col - 1)));
    }

    void Dfs(vector<vector<int>> &grid, int i, int j)
    {
        if ((i < 0) || (j < 0) || (i >= row) || (j >= col) || (grid[i][j] != 1)) {
            return;
        }

        grid[i][j] = 2;
        Dfs(grid, i + 1, j);
        Dfs(grid, i - 1, j);
        Dfs(grid, i, j + 1);
        Dfs(grid, i, j - 1);
    }

private:
    int row;
    int col;
};

int main()
{
    vector<vector<int>> grid = {{0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}};
    Solution solution;
    auto result = solution.numEnclaves(grid);
    cout << result << endl;

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>> &board)
    {
        if (board.empty()) {
            return;
        }

        row = static_cast<int>(board.size());
        col = static_cast<int>(board[0].size());

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                // 从边上的O元素及其周边为O的元素，统一标记为#，表明该O区域没有被包围
                if ((board[i][j] == 'O') && IsEdge(i, j)) {
                    Dfs(board, i, j);
                }
            }
        }

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (board[i][j] == '#') {
                    board[i][j] = 'O';
                    // 被包围的O需要置为X
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }

private:
    bool IsEdge(int i, int j) const
    {
        return (i == 0) || (j == 0) || (i == (row - 1)) || (j == (col - 1));
    }

    void Dfs(vector<vector<char>> &board, int i, int j)
    {
        if ((i < 0) || (j < 0) || (i >= row) || (j >= col) || (board[i][j] == 'X') || (board[i][j] == '#')) {
            return;
        }

        board[i][j] = '#';
        Dfs(board, i - 1, j);
        Dfs(board, i + 1, j);
        Dfs(board, i, j - 1);
        Dfs(board, i, j + 1);
    }

private:
    int row;
    int col;
};

int main()
{
    vector<vector<char>> board = {{'O','O','O'},{'O','O','O'},{'O','O','O'}};
    Solution solution{};
    solution.solve(board);
    for (const auto &i : board) {
        for (auto j : i) {
            cout << j << ' ';
        }

        cout << endl;
    }

    return 0;
}

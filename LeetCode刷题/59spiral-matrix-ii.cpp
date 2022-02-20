//
// Created by Zhang on 2021/3/18.
// https://leetcode-cn.com/problems/spiral-matrix-ii/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    static vector<vector<int>> generateMatrix(int n) {
        // vector当做二元数组使用的话先调整大小
        vector<vector<int>> result(n);
        for (auto & i : result) {
            i.resize(n);
        }

        // 上下左右边界
        int left = 0;
        int right = n - 1;
        int up = 0;
        int down = n - 1;
        int length = n * n;
        int number = 1;
        while (number <= length) {
            // 上边界，遍历之后上边界下移
            for (int le = left; le <= right; ++le) {
                result[up][le] = number;
                number++;
            }
            up++;

            // 右边界，遍历之后右边界左移
            for (int u = up; u <= down; ++u) {
                result[u][right] = number;
                number++;
            }
            right--;

            // 下边界，遍历之后下边界上移
            for (int ri = right; ri >= left; --ri) {
                result[down][ri] = number;
                number++;
            }
            down--;

            // 左边界，遍历之后左边界右移
            for (int dow = down; dow >= up; --dow) {
                result[dow][left] = number;
                number++;
            }
            left++;
        }

        return result;
    }
};

int main()
{
    auto result = Solution::generateMatrix(3);
    for (const auto& i : result) {
        for (auto j : i) {
            cout << j << ' ';
        }
        cout << endl;
    }
}


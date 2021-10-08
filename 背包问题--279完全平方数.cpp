#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    static int numSquares(int n)
    {
        // 问题可以转化为完全背包问题求最值的情况，待选数字（硬币）为1到sqrt(n)
        // 目标target为n，直接套用模板外层循环nums，内存正序循环target且target>=(num * num)
        // dp[j] = min(dp[j], dp[j - (num * num)] + 1), dp[j - (num * num)] + 1表示选择该num
        vector<int> dp(n + 1, 105);
        dp[0] = 0;

        for (int num = 1; num <= sqrt(n); ++num) {
            for (int j = 0; j <= n; ++j) {
                if (j >= (num * num)) {
                    dp[j] = min(dp[j], dp[j - (num * num)] + 1);
                }
            }
        }

        return dp[n];
    }
};


int main()
{
    int n = 12;
    cout << Solution::numSquares(n) << endl;
    return 0;
}

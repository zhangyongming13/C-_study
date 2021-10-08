#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    static int change(int amount, vector<int>& coins)
    {
        // 题目可以转换为完全背包问题求组合的问题，即外层循环nums，内层正序循环target且target>=num
        // dp[j] += dp[j - num]
        vector<int> dp(amount + 1);
        dp[0] = 1;

        for (const int coin : coins) {
            for (int j = 0; j <= amount; ++j) {
                if (j >= coin) {
                    dp[j] += dp[j - coin];
                }
            }
        }

        return dp[amount];
    }
};

int main()
{
    int amount = 5;
    vector<int> coins = {1, 2, 5};
    cout << Solution::change(amount, coins) << endl;

    return 0;
}

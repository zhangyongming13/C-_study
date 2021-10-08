#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    static int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, 105);
        dp[0] = 0;

        // 属于完全背包问题，外循环nums,内循环target,target正序且target>=nums[i]
        for (const auto coin : coins) {
            for (int i = 0; i <= amount; ++i) {
                if (coin <= i) {
                    // 属于最值问题dp[i] = max/min(dp[i], dp[i-nums]+1)或dp[i] = max/min(dp[i], dp[i-num]+nums)
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        return dp[amount] == 105 ? -1 : dp[amount];
    }
};

int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    cout << Solution::coinChange(coins, amount) << endl;
}
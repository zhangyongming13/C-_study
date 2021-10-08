#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    static int combinationSum4(vector<int>& nums, int target)
    {
        // 题目可以转换为组合背包问题求组合问题，外层正序循环target且target>=num，内层循环
        // nums，组合问题dp[j] += dp[j - num]
        vector<unsigned long long> dp(target + 1);
        dp[0] = 1;

        for (int j = 1; j <= target; ++j) {
            for (const int num : nums) {
                if (j >= num) {
                    dp[j] += dp[j - num];
                }
            }
        }

        return static_cast<int>(dp[target]);
    }
};

int main()
{
    vector<int> nums = {1,2,3};
    int target = 4;
    cout << Solution::combinationSum4(nums, target) << endl;

    return 0;
}

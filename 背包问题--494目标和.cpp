#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    static bool canPartition(vector<int> &nums)
    {
        // 题目可以转换为能否在数据中选择若干个数组成子数组，使得子数组的和为
        // 数组和的一半，这样实际就是0/1背包存在问题，直接套用模板即可
        int sum = 0;
        for (const int num : nums) {
            sum += num;
        }

        // 数组和为奇数，一定不能分割成两个相等的子数组
        if ((sum % 2) == 1) {
            return false;
        }

        // 目标target为数组和的一般
        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        // 0/1背包问题，外层循环nums，内层倒序循环target且i >= nums
        for (const int num : nums) {
            for (int i = target; i >= 0; --i) {
                if (i >= num) {
                    // 存在性问题套用模板dp[i] = dp[i] || dp[i - num]
                    dp[i] = dp[i] || dp[i - num];
                }
            }
        }

        return dp[target];
    }
};


int main()
{
    vector<int> nums = {1,5,11,5};
    if (Solution::canPartition(nums)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

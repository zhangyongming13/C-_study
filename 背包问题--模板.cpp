#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    static int Bags(vector<int> &nums, vector<int> &value, int bagsSize)
    {
        vector<int> dp(bagsSize + 1, 0);

        // 外层循环，根据不同的背包问题而不同
        for (int i = 0; i < nums.size(); ++i) {
            // 内层循环，根据不同的背包问题而不同
            for (int j = bagsSize; j >= nums[i]; --j) {
                if (j >= nums[i]) {
                    // dp赋值，根据不同的背包问题而不同
                    dp[j] = max(dp[j], dp[j - nums[i]] + value[i]);
                }
            }
        }

        return dp[bagsSize];
    }
};

int main()
{
    vector<int> nums = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagsSize = 4;

    cout << Solution::Bags(nums, value, bagsSize) << endl;
}

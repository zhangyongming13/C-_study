#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    static int subarraySum(vector<int> &nums, int k)
    {
        int numsSize = static_cast<int>(nums.size());
        // 前缀和数组因为包含一个起始位0，所以大小需要加1
        vector<int> preSumVec(numsSize + 1);
        // 计算前缀和数组
        for (int i = 1; i < (numsSize + 1); ++i) {
            preSumVec[i] = preSumVec[i - 1] + nums[i - 1];
        }

        // 前缀和遍历求结果--这里以子数组和为k为例，这样属于暴利解法，在有时间限制的地方会超时
        // 优化方法一般使用map，根据不同的要求，设计不同的map，具体可以参照leetcode的560和974题
        int result = 0;
        for (int i = 0; i < numsSize; ++i) {
            for (int j = i; j < numsSize; ++j) {
                if ((preSumVec[j + 1] - preSumVec[i]) == k) {
                    result++;
                }
            }
        }

        return result;
    }
};

int main()
{
    vector<int> nums = {1,1,1};
    int k = 3;
    auto result = Solution::subarraySum(nums, k);
    cout << result << endl;

    return 0;
}

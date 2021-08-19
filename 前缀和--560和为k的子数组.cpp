#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    static int subarraySum(vector<int> &nums, int k)
    {
        int numsSize = static_cast<int>(nums.size());
        vector<int> sumVec(numsSize + 1);
        int result = 0;

        // 先计算出前缀和
        for (int i = 1; i < (numsSize + 1); ++i) {
            sumVec[i] = sumVec[i - 1] + nums[i - 1];
        }

        // 这里map的key是前缀和的值，value是该前缀和出现的次数
        unordered_map<int, int> sumMap;
        // 如果一个前缀和减去k刚好是0的话那么这个前缀和对应位置到0的子数组就满足条件
        sumMap[0] = 1;
        for (int i = 1; i < (numsSize + 1); ++i) {
            int tmp = sumVec[i] - k;
            // 这里看做题目条件可以看做preSum1 - preSum2 = k，可以转换为preSum1 - k = preSum2，
            // 即该preSum1对应的位置到preSum2对应的位置的子数组的和就是k
            if (sumMap.count(sumVec[i] - k)) {
                result += sumMap[sumVec[i] - k];
            }

            // 这里需要注意的是前缀和加1
            sumMap[sumVec[i]]++;
        }

        return result;
    }
};

int main()
{
    vector<int> nums = {1,1,1};
    int k = 2;
    auto result = Solution::subarraySum(nums, k);
    cout << result << endl;

    return 0;
}

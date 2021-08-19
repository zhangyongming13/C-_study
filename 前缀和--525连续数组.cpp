#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    static int findMaxLength(vector<int> &nums)
    {
        int numsSize = static_cast<int>(nums.size());
        vector<int> preSumVec(numsSize + 1);
        preSumVec[0] = 0;
        // 这里计算前缀和的时候需要注意0是-1，方便计算，一个子数组中0和1相等，那个和就为0
        for (int i = 1; i < (numsSize + 1); ++i) {
            int tmp = nums[i - 1] == 0 ? -1 : 1;
            preSumVec[i] = preSumVec[i - 1] + tmp;
        }

        // 子数组内0和1个数相等，可以转换为preSum1 - preSum2 = 0即preSum1 = preSum2
        // 因为子数组0和1个数相等的话，那么子数组的和必为0
        unordered_map<int, int> preSumMap;
        preSumMap[0] = 0;
        int result = 0;
        for (int i = 1; i < (numsSize + 1); ++i) {
            if (preSumMap.count(preSumVec[i]) != 0) {
                if ((i - preSumMap[preSumVec[i]]) > result) {
                    result = i - preSumMap[preSumVec[i]];
                }
            } else {
                // 因为计算的是最长，所以不能更新Index，如果是求最短则需要每次都更新index
                preSumMap[preSumVec[i]] = i;
            }
        }

        return result;
    }
};

int main()
{
    vector<int> nums = {0,1,0};
    auto result = Solution::findMaxLength(nums);
    cout << result << endl;

    return 0;
}

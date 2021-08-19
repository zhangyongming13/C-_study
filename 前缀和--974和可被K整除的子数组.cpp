#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    static int subarraysDivByK(vector<int> &nums, int k)
    {
        int numsSize = static_cast<int>(nums.size());
        // 前缀和数组初始化
        vector<int> preSumVec(numsSize + 1);
        preSumVec[0] = 0;
        for (int i = 1; i < (numsSize + 1); ++i) {
            preSumVec[i] = preSumVec[i - 1] + nums[i - 1];
        }

        // 子数组和可以被K整除可以转换为(preSum1 - preSum2) % K = 0，再次转换为
        // preSum1 % k = preSum2 % K，这样就可以设计一个map，key为preSum % K，keyValue为出现次数
        unordered_map<int, int> preNumMap;
        preNumMap[0] = 1;
        int result = 0;
        for (int i = 1; i < (numsSize + 1); ++i) {
            // 这里需要注意的是某些情况下preSum可能为负，负的余数不符合常理，所以统一进行这样的计算避免负数
            int tmpKey = (preSumVec[i] % k + k) % k;
            if (preNumMap.count(tmpKey) != 0) {
                result += preNumMap[tmpKey];
            }

            preNumMap[tmpKey]++;
        }

        return result;
    }
};

int main()
{
    vector<int> nums = {4,5,0,-2,-3,1};
    int k = 5;
    auto result = Solution::subarraysDivByK(nums, k);
    cout << result << endl;

    return 0;
}

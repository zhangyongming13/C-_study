#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    static bool checkSubarraySum(vector<int> &nums, int k)
    {
        int numsSize = static_cast<int>(nums.size());
        vector<int> preSumVec(numsSize + 1);
        preSumVec[0] = 0;
        for (int i = 1; i < (numsSize + 1); ++i) {
            preSumVec[i] = preSumVec[i - 1] + nums[i - 1];
        }

        // map的key为preSum % K， keyValue为对应的key第一次出现的index
        unordered_map<int, int> preSumMap;
        preSumMap[0] = 0;
        for (int i = 1; i < (numsSize + 1); ++i) {
            int tmp = preSumVec[i] % k;
            if (preSumMap.count(tmp) != 0) {
                if ((i - preSumMap[tmp]) >= 2) {
                    return true;
                }
            } else {
                // 这里需要注意的就是不能更新下标
                preSumMap[tmp] = i;
            }
        }

        return false;
    }
};

int main()
{
    vector<int> nums = {0,1,0,3,0,4,0,4,0};
    int k = 5;
    cout << Solution::checkSubarraySum(nums, k) << endl;

    return 0;
}

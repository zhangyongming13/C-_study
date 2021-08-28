#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    static vector<int> runningSum(vector<int> &nums)
    {
        vector<int> preSum(nums.size(), 0);
        preSum[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            preSum[i] = preSum[i - 1] + nums[i];
        }

        return preSum;
    }
};

int main()
{
    vector<int> nums = {1,2,3,4};
    auto result = Solution::runningSum(nums);
    for (const auto i : result) {
        cout << i << ' ';
    }

    return 0;
}

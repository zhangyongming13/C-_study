#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    static int minSubArrayLen(int target, vector<int> &nums)
    {
        int result = static_cast<int>(nums.size()) + 1;
        int left = 0;
        int sum = 0;
        for (int right = 0; right < nums.size(); ++right) {
            sum += nums[right];

            // 左指针向右移动缩小范围
            while (sum >= target) {
                result = min(result, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }

        if (result == (static_cast<int>(nums.size()) + 1)) {
            return 0;
        }

        return result;
    }
};

int main()
{
    int target = 7;
    vector<int> nums = {2,3,1,2,4,3};
    auto result = Solution::minSubArrayLen(target, nums);
    cout << result << endl;

    return 0;
}

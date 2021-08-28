#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    static int meetingRooms(vector<vector<int>> &plans)
    {
        int maxEndTime = 102;
        // 先求diff数组
        vector<int> diff(maxEndTime, 0);
        for (const auto &plan : plans) {
            diff[plan[0]] += 1;
            diff[plan[1] + 1] -= 1;
        }

        // 求差分前缀和数组
        vector<int> preSum(maxEndTime, 0);
        // 这里需要注意的是，会议时间可能从0开始，所以差分前缀和也应该从0初始化
        preSum[0] = diff[0];
        for (int i = 1; i < maxEndTime; ++i) {
            preSum[i] = preSum[i - 1] + diff[i];
        }

        int result = 0;
        // 求最大值就是至少需要准备多少会议室
        for (const auto i : preSum) {
            result = result < i ? i : result;
        }

        return result;
    }
};

int main()
{
    vector<vector<int>> plans = {{7, 10}, {2, 4}, {3, 10}, {11, 90}};
    cout << Solution::meetingRooms(plans) << endl;
}

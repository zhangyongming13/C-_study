#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    static vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n)
    {
        // 求diff数组，这里需要注意的是n + 2因为在右边界是+1的地方需要处理
        vector<int> diff(n + 2, 0);
        for (const auto &booking : bookings) {
            diff[booking[0]] += booking[2];
            diff[booking[1] + 1] -= booking[2];
        }

        // 求差分前缀和，这里的前缀和除了第一个元素，剩下的就是需要的结果
        vector<int> preSum(n + 1, 0);
        for (int i = 1; i < n + 1; ++i) {
            preSum[i] = preSum[i - 1] + diff[i];
        }

        preSum.erase(preSum.begin());
        return preSum;
    }
};

int main()
{
    vector<vector<int>> bookings = {{1,2,10},{2,3,20},{2,5,25}};
    int n = 5;
    vector<int> result = Solution::corpFlightBookings(bookings, n);
    for (const auto i : result) {
        cout << i << ' ';
    }

    return 0;
}

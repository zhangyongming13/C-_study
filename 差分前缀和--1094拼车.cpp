#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    static bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        int tripMaxLength = 1001;
        // 先求diff数组，遇到左边界代表上车乘客，遇到右边界代表乘客下车
        vector<int> diff(tripMaxLength, 0);
        for (const auto &trip : trips) {
            // 这里加减乘客模拟上下车
            diff[trip[1]] += trip[0];
            diff[trip[2]] -= trip[0];
        }

        // 求差分前缀和数组，得到的数组就是在这个时间车上乘客的数量
        vector<int> preSum(tripMaxLength, 0);
        preSum[0] = diff[0];
        for (int i = 1; i < tripMaxLength; ++i) {
            preSum[i] = preSum[i - 1] + diff[i];
        }

        // 判断车上乘客数量是否超过空位的数量
        for (int i = 0; i < tripMaxLength; ++i) {
            if (preSum[i] > capacity) {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    vector<vector<int>> trips = {{2,1,5},{3,3,7}};
    int capacity = 4;
    if (Solution::carPooling(trips, capacity)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}

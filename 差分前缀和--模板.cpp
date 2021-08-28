#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    static bool isCovered(vector<vector<int>> &ranges, int left, int right)
    {
        // 依照题目的不同而不同
        int maxRangeLength = 52;
        // 先求diff数组，出现的左边界+1，出现的右边界的右侧-1，这数值不一定是1要看具体题目而定
        vector<int> diff(maxRangeLength, 0);
        for (const auto &range : ranges) {
            diff[range[0]] += 1;
            diff[range[1] + 1] -= 1;
        }

        // 求差分前缀和，这里普通的前缀和不一样的是，上一个数是diff，上一个前缀和不变
        vector<int> preSum(maxRangeLength, 0);
        for (int i = 1; i < maxRangeLength; ++i) {
            preSum[i] = preSum[i - 1] + diff[i];
        }

        // 在范围内如果有小于等于0的则说明没有被覆盖到，这个是数字被覆盖的次数，这里判断条件不一定是小于0之类的
        for (int i = left; i <= right; ++i) {
            if (preSum[i] <= 0) {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    vector<vector<int>> ranges = {{1,1}};
    if (Solution::isCovered(ranges, 1, 50)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}

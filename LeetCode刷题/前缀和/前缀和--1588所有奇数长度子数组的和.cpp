#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    static int sumOddLengthSubarrays(vector<int> &arr)
    {
        // 这里以例题数据为例{1,4,2,5,3}其中子数组{2，5，3}这个的和就是3这个位置的前缀和减去2之前一个位置的前缀和
        // 这样我们可以先求前缀和，然后根据长度进行减法就可以知道这个子数组的和
        int arrLength = static_cast<int>(arr.size());
        vector<int> preSum(arrLength + 1, 0);
        for (int i = 1; i < (arrLength + 1); ++i) {
            preSum[i] = preSum[i - 1] + arr[i - 1];
        }

        int result = 0;
        for (int len = 1; len <= arrLength; len += 2) {
            for (int left = 0; (left + len) <= arrLength; ++left) {
                result += preSum[left + len] - preSum[left];
            }
        }

        return result;
    }
};

int main()
{
    vector<int> arr = {1,4,2,5,3};
    cout << Solution::sumOddLengthSubarrays(arr) << endl;

    return 0;
}

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    static int longestOnes(vector<int> &nums, int k)
    {
        int numsSize = static_cast<int>(nums.size());
        int left = 0;
        int length = 0;
        int zeroNum = 0;
        for (int right = 0; right < numsSize; ++right) {
            if (nums[right] == 0) {
                zeroNum++;
            }

            // 移动左指针直到遇到0，因为会进入这个分支肯定是右指针遇到了0，所以左指针再次遇到0的时候，右指针才能动，否则违反0变1的个数
            while (zeroNum > k) {
                if (nums[left] == 0) {
                    zeroNum--;
                }

                left++;
            }

            length = max(length, right - left + 1);
        }

        return length;
    }
};

int main()
{
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int K = 2;
    auto result = Solution::longestOnes(nums, K);
    cout << result << endl;

    return 0;
}

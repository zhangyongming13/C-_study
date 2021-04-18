#include <vector>
#include <iostream>

//https://leetcode-cn.com/problems/longest-continuous-increasing-subsequence/

using namespace std;

class Solution {
public:
    static int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int maxLength = 0;
        for (int i = 0; i < (nums.size() - 1);) {
            int tempLength = 0;
            int j = i + 1;
            for (; j < nums.size(); ++j) {
                if (nums[j] > nums[j - 1]) {
                    tempLength++;
                } else {
                    break;
                }
            }
            i = j;

            if (tempLength > maxLength) {
                maxLength = tempLength;
            }
        }

        return maxLength + 1;
    }
};

int main()
{
    vector<int> nums = {};
    cout << Solution::findLengthOfLCIS(nums) << endl;
}

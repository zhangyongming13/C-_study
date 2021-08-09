#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    static int longestConsecutive(vector<int>& nums)
    {
        if (nums.empty()) {
            return 0;
        }

        sort(nums.begin(), nums.end());

        int result = 1;
        int tmp = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == (nums[i - 1] + 1)) {
                tmp++;
            } else if (nums[i] == nums[i - 1]) {
                continue;
            } else {
                if (tmp > result) {
                    result = tmp;
                }

                tmp = 1;
            }
        }

        if (tmp > result) {
            result = tmp;
        }

        return result;
    }
};

int main()
{
    vector<int> nums = {1, 2, 0, 1};
    int result = Solution::longestConsecutive(nums);

    cout << result << endl;
}

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    static vector<vector<int>> threeSum(vector<int>& nums)
    {
        int numSize = static_cast<int>(nums.size());
        if (numSize < 3) {
            return {};
        }

        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < numSize; ++i) {
            // 这里避免连续相同的数存入重复数组
            if ((i > 0) && (nums[i] == nums[i - 1])) {
                continue;
            }

            int left = i + 1;
            int right = numSize - 1;
            while (left < right) {
                int tmpSum = nums[i] + nums[left] + nums[right];
                if (tmpSum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});

                    while ((left < right) && (nums[left] == nums[left + 1])) {
                        left++;
                    }

                    while ((left < right) && (nums[right] == nums[right - 1])) {
                        right--;
                    }

                    left++;
                    right--;
                } else if (tmpSum > 0) {
                    right--;
                } else if (tmpSum < 0) {
                    left++;
                }
            }
        }

        return result;
    }
};

int main()
{
    vector<int> nums = {-1,0,1,2,-1};
    auto result = Solution::threeSum(nums);
    for (const auto &item : result) {
        for (const auto i : item) {
            cout << i << ' ';
        }

        cout << endl;
    }

    return 0;
}

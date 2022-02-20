#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    static vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() < 3) {
            return result;
        }

        sort(nums.begin(), nums.end());
        unsigned int numsSize = nums.size();
        for (unsigned int i = 0; i < numsSize; ++i) {
            // 和上一个元素重复直接跳过
            if ((i > 0) && (nums[i] == nums[i - 1])) {
                continue;
            }

            unsigned int left = i + 1;
            unsigned int right = numsSize - 1;
            while (left < right) {
                int tmpValue = nums[i] + nums[left] + nums[right];
                if (tmpValue == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});

                    // 跳过重复的元素
                    while ((left < right) && (nums[left] == nums[left + 1])) {
                        left++;
                    }
                    while ((left < right) && (nums[right] == nums[right - 1])) {
                        right--;
                    }

                    // 这里都需要++和--，因为上面只是跳过重复元素，还需要++和--到达新的元素
                    left++;
                    right--;
                    // 偏大，右边的窗口需要向左缩
                } else if (tmpValue > 0) {
                    right--;
                    // 偏小，左边的窗口需要向右缩
                } else {
                    left++;
                }
            }
        }

        return result;
    }
};

int main()
{
    vector<int> nums = {-1,0,1,2,-1,-4};
    auto result = Solution::threeSum(nums);
    for (const auto& i : result) {
        for (auto j : i) {
            cout << j << ' ';
        }
        cout << endl;
    }

    return 0;
}

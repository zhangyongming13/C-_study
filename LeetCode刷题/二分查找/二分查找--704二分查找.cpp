#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    static int search(vector<int>& nums, int target)
    {
        int numsSize = static_cast<int>(nums.size());
        int left = 0;
        int right = numsSize - 1;
        int mid = 0;
        while (left <= right) {
            // 避免直接相加导致溢出的问题
            mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            }
        }

        return -1;
    }
};

int main()
{
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 9;
    cout << Solution::search(nums, target) << endl;

    return 0;
}

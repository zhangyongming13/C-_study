#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    static int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        if (nums.size() == 1) {
            return 1;
        }

        int left = 0;
        int right = 1;
        while (right < nums.size()) {
            if (nums[left] != nums[right]) {
                nums[left + 1] = nums[right];
                left++;
            }

            right++;
        }

        return left + 1;
    }
};

int main()
{
    vector<int> nums ={0,0,1,1,1,2,2,3,3,4};
    int result = Solution::removeDuplicates(nums);
    for (int i = 0; i < result; ++i) {
        cout << nums[i] << ' ';
    }

    return 0;
}

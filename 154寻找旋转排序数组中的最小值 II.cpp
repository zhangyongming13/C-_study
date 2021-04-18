#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static int findMin(vector<int>& nums) {
        for (auto i : nums) {
            if (i < nums[0]) {
                return i;
            }
        }

        return nums[0];
    }
};

int main()
{
    vector<int> nums = {2,5,6,0,0,1,2};
    cout << Solution::findMin(nums) << endl;
    return 0;
}

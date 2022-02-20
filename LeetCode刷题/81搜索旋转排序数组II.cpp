#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static bool search(vector<int>& nums, int target) {
        for (auto i : nums) {
            if (i == target) {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    vector<int> nums = {2,5,6,0,0,1,2};
    int target = 3;
    if (Solution::search(nums, target)) {
        cout << "true" << endl;
    }
    return 0;
}

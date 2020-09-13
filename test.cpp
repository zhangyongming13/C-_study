#include <vector>
#include <iostream>

// https://leetcode-cn.com/problems/remove-element/

using namespace std;

class Solution {
public:
    static int removeElement(vector<int>& nums, int val) {
        int newLength = 0;
        for (auto i : nums) {
            if (val != i) {
                nums[newLength] = i;
                newLength += 1;
            }
        }
        return newLength; } };

int main() {
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;
    cout << Solution::removeElement(nums, val) << endl;
    for (auto i : nums) {
        cout << i << ' ';
    }
    cout << endl; return 0;
}
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    static int maxArea(vector<int>& height) {
        if (height.size() <= 1) {
            return 0;
        }

        int result = 0;
        int left = 0;
        int right = int(height.size()) - 1;
        int tmpResult = 0;
        while (left != right) {
            // 每次都是缩最短的那条边
            if (height[left] >= height[right]) {
                tmpResult = height[right] * (right - left);
                right--;
            } else {
                tmpResult = height[left] * (right - left);
                left++;
            }

            result = result > tmpResult ? result : tmpResult;
        }

        return result;
    }
};

int main()
{
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << Solution::maxArea(height) << endl;

    return 0;
}

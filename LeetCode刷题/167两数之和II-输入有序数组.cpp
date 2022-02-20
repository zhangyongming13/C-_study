#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    static vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        int left = 0;
        int right = int(numbers.size()) - 1;

        while (left < right) {
            if ((numbers[left] + numbers[right]) == target) {
                result.push_back(left + 1);
                result.push_back(right + 1);

                return result;
            } else if ((numbers[left] + numbers[right]) > target) {
                right--;
            } else {
                left++;
            }
        }

        return result;
    }
};

int main()
{
    vector<int> numbers = {2,3,4};
    int target = 6;
    auto result = Solution::twoSum(numbers, target);
    for (auto i : result) {
        cout << i << ' ';
    }

    return 0;
}

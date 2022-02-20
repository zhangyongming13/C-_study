#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct Numbers
{
public:
    Numbers(int num1, int num2)
    {
        number1 = num1;
        number2 = num2;
        sum = num1 + num2;
    }

    bool operator < (const Numbers &other) const
    {
        return sum < other.sum;
    }

public:
    int number1;
    int number2;
    int sum;
};

class Solution {
public:
    static vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k)
    {
        int nums1Size = static_cast<int>(nums1.size());
        int nums2Size = static_cast<int>(nums2.size());

        priority_queue<Numbers> numberQueue;
        for (int i = 0; i < min(k, nums1Size); ++i) {
            for (int j = 0; j < min(k, nums2Size); ++j) {
                if (numberQueue.size() == k) {
                    if ((nums1[i] + nums2[j]) < numberQueue.top().sum) {
                        numberQueue.pop();
                        Numbers numbers(nums1[i], nums2[j]);
                        numberQueue.push(numbers);
                    }
                } else {
                    Numbers numbers(nums1[i], nums2[j]);
                    numberQueue.push(numbers);
                }
            }
        }

        vector<vector<int>> result;
        while ((!numberQueue.empty())) {
            result.push_back({numberQueue.top().number1, numberQueue.top().number2});
            numberQueue.pop();
        }

        return result;
    }
};

int main()
{
    vector<int> nums1 = {1,7,11};
    vector<int> nums2 = {2,4,6};
    int k = 3;
    auto result = Solution::kSmallestPairs(nums1, nums2, k);
    for (const auto &nums : result) {
        for (const auto &item : nums) {
            cout << item << ' ';
        }

        cout << endl;
    }

    return 0;
}

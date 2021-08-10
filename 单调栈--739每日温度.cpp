#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    static vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        unsigned int temperaturesSize = temperatures.size();
        vector<int> result(temperaturesSize);

        if (temperaturesSize == 0) {
            return result;
        }

        stack<int> indexStack;

        for (int i = (static_cast<int>(temperaturesSize) - 1); i >= 0; --i) {
            while (!indexStack.empty() && (temperatures[i] >= temperatures[indexStack.top()])) {
                indexStack.pop();
            }

            result[i] = indexStack.empty() ? 0 : (indexStack.top() - i);
            indexStack.push(i);
        }

        return result;
    }
};

int main()
{
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    auto result = Solution::dailyTemperatures(temperatures);

    for (auto i : result) {
        cout << i << ' ';
    }
}

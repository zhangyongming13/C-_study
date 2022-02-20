#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        this->classCandidates = candidates;
        int tmpSum = 0;
        vector<int> trace;
        backTrace(trace, tmpSum, target, 0);

        return result;
    }

private:
    void backTrace(vector<int> &trace, int tmpSum,int target, int step) {
        if (tmpSum == target) {
            result.push_back(trace);
            return;
        } else if (tmpSum > target) {
            return;
        } else {
            for (int i = step; i < classCandidates.size(); ++i) {
                trace.push_back(classCandidates[i]);
                tmpSum += classCandidates[i];
                // 这里因为不限制每个元素使用的次数所以传的事i而不是i+1
                backTrace(trace, tmpSum, target, i);
                trace.pop_back();
                tmpSum -= classCandidates[i];
            }
        }
    }

private:
    vector<int> classCandidates;
    vector<vector<int>> result;
};

int main()
{
    Solution solution;
    vector<int> candidates = {2,7,6,3,5,1};
    int target = 9;
    auto result = solution.combinationSum(candidates, target);
    for (const auto& i : result) {
        for (auto j : i) {
            cout << j << ' ';
        }

        cout << endl;
    }

    return 0;
}

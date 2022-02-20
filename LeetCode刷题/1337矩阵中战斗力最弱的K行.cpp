#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    static vector<int> kWeakestRows(vector<vector<int>>& mat, int k)
    {
        vector<pair<int, int>> matVec;
        for (int i = 0; i < mat.size(); ++i) {
            // 求每一行对应的pair，key为行数，value为战斗力
            pair<int, int> tmpPair;
            tmpPair.first = i;
            tmpPair.second = VecSum(mat[i]);
            matVec.emplace_back(tmpPair);
        }

        // 进行排序，并且传入比较函数
        sort(matVec.begin(), matVec.end(), cmp);

        vector<int> result;
        result.reserve(k);
        for (int i = 0; i < k; ++i) {
            result.push_back(matVec[i].first);
        }

        return result;
    }

private:
    static int VecSum(const vector<int> &inputVec)
    {
        int result = 0;
        for (auto i : inputVec) {
            result += i;
        }

        return result;
    }

    // 自定义比较函数，先比较键值value，键值value相同再按照key进行排序
    static bool cmp(const pair<int, int> &input1, const pair<int, int> &input2)
    {
        if (input1.second < input2.second) {
            return true;
        } else if (input1.second > input2.second) {
            return false;
        } else {
            return input1.first < input2.first;
        }
    }
};

int main()
{
    vector<vector<int>> mat = {{1,1,1,1,1,1},{1,1,1,1,1,1},{1,1,1,1,1,1}};
    auto result = Solution::kWeakestRows(mat, 1);

    for (auto i : result) {
        cout << i << ' ';
    }

    return 0;
}

#include <vector>
#include <iostream>

using namespace std;

const int vecSize = 1000;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges)
    {
        Init(vecSize);
        for (auto & edge : edges) {
            if (Find(edge[0]) == Find(edge[1])) {
                return edge;
            } else {
                Merge(edge[0], edge[1]);
            }
        }

        vector<int> result;
        return result;
    }

private:
    void Init(int inputSize)
    {
        for (int i = 0; i < inputSize; ++i) {
            jointSearVec.emplace_back(i);
        }
    }

    int Find(int x)
    {
        if (jointSearVec[x] == x) {
            return x;
        } else {
            jointSearVec[x] = Find(jointSearVec[x]);
            return jointSearVec[x];
        }
    }

    void Merge(int i, int j)
    {
        jointSearVec[Find(i)] = Find(j);
    }

private:
    vector<int> jointSearVec;
};

int main()
{
    vector<vector<int>> edges = {{1,2},{1,3},{2,3}};
    Solution solution;
    auto result = solution.findRedundantConnection(edges);
    for (auto i : result) {
        cout << i << ' ';
    }

    return 0;
}

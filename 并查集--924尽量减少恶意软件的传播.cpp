#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minMalwareSpread(vector<vector<int>> &graph, vector<int> &initial)
    {
        int row = static_cast<int>(graph.size());
        Init(row);
        // 并查集并的操作
        MergeGraph(graph, row, initial);

        int result = 0;
        int max = 0;
        // 先排序，因为在相同情况下要返回索引最小的节点，这里的索引不是指initial的索引，可以理解为小到达的意思
        sort(initial.begin(), initial.end());
        for (int i : initial) {
            int root = Find(i);
            int count = 0;
            // 计算属于这个集合的元素的多少，因为和一个感染的节点在同一个集合那么必定会被感染，要删的节点就是集合最大且只有一个感染点，如果有多个
            // 感染节点，单独删除一个并不能让这个集合不被感染
            for (int j = 0; j < row; ++j) {
                if (root == Find(j)) {
                    // 判断集合中是否还有其他节点在initial中即感染了病毒
                    if (IsExistInVec(initial, j) && (i != j)) {
                        count = 0;
                        break;
                    }
                    count++;
                }
            }

            if (count > max) {
                result = i;
                max = count;
            }
        }

        // 如果没有找到删除的点，那就直接删除索引最小的
        if ((result == 0) && !IsExistInVec(initial, 0)) {
            return *initial.begin();
        }

        return result;
    }

private:
    static bool IsExistInVec(const vector<int> &initial, int i)
    {
        auto iter = find(initial.begin(), initial.end(), i);
        if (iter != initial.end()) {
            return true;
        }

        return false;
    }

    void MergeGraph(const vector<vector<int>> &graph, int row, const vector<int> &initial)
    {
        for (int i = 0; i < row; ++i) {
            for (int j = i + 1; j < row; ++j) {
                if ((i != j) && (graph[i][j] == 1)) {
                    if (IsExistInVec(initial, j)) {
                        Merge(j, i);
                    } else {
                        Merge(i, j);
                    }
                }
            }
        }
    }

    void Init(int vecSize)
    {
        unionFindVec.resize(vecSize);
        for (int i = 0; i < vecSize; ++i) {
            unionFindVec[i] = i;
        }
    }

    int Find(int x)
    {
        if (unionFindVec[x] == x) {
            return x;
        } else {
            unionFindVec[x] = Find(unionFindVec[x]);
            return unionFindVec[x];
        }
    }

    void Merge(int i, int j)
    {
        unionFindVec[Find(j)] = Find(i);
    }

private:
    vector<int> unionFindVec;
};

int main()
{
    vector<vector<int>> graph = {{1,1,0},{1,1,0},{0,0,1}};
    vector<int> initial = {0,1};
    Solution solution;
    auto result = solution.minMalwareSpread(graph, initial);
    cout << result << endl;

    return 0;
}

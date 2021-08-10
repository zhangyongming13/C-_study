#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges)
    {
        vector<int> inDegree(1005);
        int edgeSize = static_cast<int>(edges.size());
        // 计算节点的入度（该节点有多少个父节点）
        for (int i = (edgeSize - 1); i >=0; i--) {
            inDegree[edges[i][1]]++;
        }

        // 记录入度为2结点对应的边，存在的话就有两条
        vector<int> vec;
        for (int i = (edgeSize - 1); i >= 0; --i) {
            if (inDegree[edges[i][1]] == 2) {
                vec.emplace_back(i);
            }
        }

        // 存在入度为2的结点，将其对应的边删除之后，判断是否符合要求
        if (!vec.empty()) {
            if (isTreeAfterRemoveEdge(edges, vec[0])) {
                return edges[vec[0]];
            } else {
                return edges[vec[1]];
            }
        }

        // 没有入度为2的节点直接判断是否符合要求即冗余连接I
        return GetRemoveEdge(edges);
    }

private:
    // 初始化并查集
    void Init(int vecSize)
    {
        unionFindVec.resize(vecSize);
        for (int i = 0; i < vecSize; ++i) {
            unionFindVec[i] = i;
        }
    }

    // 并查集找根结点
    int Find(int x)
    {
        if (unionFindVec[x] == x) {
            return x;
        } else {
            unionFindVec[x] = Find(unionFindVec[x]);
            return unionFindVec[x];
        }
    }

    // 将j及其相关的元素并入的i中
    void Merge(int i, int j)
    {
        unionFindVec[Find(j)] = Find(i);
    }

    // 判断是否是同一个根
    bool Same(int i, int j)
    {
        return Find(i) == Find(j);
    }

    // 在没有入度为2的情况下，判断是不是树，即原来冗余连接I的情况
    vector<int> GetRemoveEdge(const vector<vector<int>> &edges)
    {
        Init(1005);
        for (const auto & edge : edges) {
            if (Same(edge[0], edge[1])) {
                return edge;
            }

            Merge(edge[0], edge[1]);
        }

        return {};
    }

    // 在有入度为2的情况下，删除一条边，判断是否符合要求
    bool isTreeAfterRemoveEdge(const vector<vector<int>> &edge, int deleteEdge)
    {
        Init(1005);
        for (int i = 0; i < edge.size(); ++i) {
            // 要删除的边就不参加到并查集的计算之中
            if (i == deleteEdge) {
                continue;
            }

            if (Same(edge[i][0], edge[i][1])) {
                return false;
            }

            Merge(edge[i][0], edge[i][1]);
        }

        return true;
    }

private:
    vector<int> unionFindVec;
};

int main()
{
    vector<vector<int>> edges = {{2,1},{3,1},{4,2},{1,4}};
    Solution solution;
    auto result = solution.findRedundantDirectedConnection(edges);
    for (auto i : result) {
        cout << i << endl;
    }

    return 0;
}

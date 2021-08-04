#include <vector>

using namespace std;

class JointSearch {
public:
    explicit JointSearch(int vecSize)
    {
        // 初始化操作，一开始的时候所有的人帮主（代表）都是自己
        for (int i = 0; i < vecSize; ++i) {
            jointSearchVec[i] = i;
        }
    }

    // 寻找x元素的帮主（代表），帮主（代表）就是就是自己
    int Find(int x)
    {
        if (jointSearchVec[x] == x) {
            return x;
        } else {
            // 将x元素上一层作为入参去查找，并做一次路径压缩算法
            jointSearchVec[x] = Find(jointSearchVec[x]);
            return jointSearchVec[x];
        }
    }

    // 将i以及它的小弟并入j所在的帮派
    void Merge(int i, int j)
    {
        jointSearchVec[Find(i)] = Find(j);
    }

private:
    vector<int> jointSearchVec;
};

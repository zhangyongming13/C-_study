#include <map>
#include <vector>
#include <iostream>

using namespace std;

class UnionFind {
public:
    explicit UnionFind(vector<int> &nums)
    {
        for (auto i : nums) {
            parent[i] = i;
            parent[i + 1] = i + 1;
        }
    }

    int Find(int x)
    {
        if (parent[x] == x) {
            return x;
        } else {
            parent[x] = Find(parent[x]);
            return parent[x];
        }
    }

    void Merge(int i, int j)
    {
        int rootI = Find(i);
        int rootJ = Find(j);
        if (rootI > rootJ) {
            parent[rootI] = rootJ;
        } else {
            parent[rootJ] = rootI;
        }
    }

private:
    map<int, int> parent;
};

class Solution {
public:
    static int longestConsecutive(vector<int> &nums)
    {
        if (nums.empty()) {
            return 0;
        }

        UnionFind unionFind(nums);
        for (auto i :  nums) {
            unionFind.Merge(i, i + 1);
        }

        int max = 1;
        for (auto i : nums) {
            int tmp = i - unionFind.Find(i) + 1;
            if (max < tmp) {
                max = tmp;
            }
        }

        return max;
    }
};

int main()
{
    vector<int> nums = {100,4,200,1,3,2};
    auto result = Solution::longestConsecutive(nums);
    cout << result << endl;

    return 0;
}

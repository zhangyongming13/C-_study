#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

class UnionFind {
public:
    explicit UnionFind(int i)
    {
        unionVec.resize(i);
        for (int j = 0; j < i; ++j) {
            unionVec[j] = j;
        }
    }

    int Find(int x)
    {
        if (unionVec[x] == x) {
            return x;
        } else {
            unionVec[x] = Find(unionVec[x]);
            return unionVec[x];
        }
    }

    void Merge(int i, int j)
    {
        unionVec[Find(j)] = Find(i);
    }

private:
    vector<int> unionVec;
};

class Solution {
public:
    static vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        // 这里保存的是账号以及对应的行数
        unordered_map<string, int> strMap;
        int row = static_cast<int>(accounts.size());
        UnionFind unionFind(row);

        for (int i = 0; i < row; ++i) {
            int col = static_cast<int>(accounts[i].size());
            for (int j = 1; j < col; ++j) {
                string tmpStr =  accounts[i][j];
                // 判断账号是否出现过
                if (strMap.count(accounts[i][j]) == 0) {
                    strMap[accounts[i][j]] = i;
                } else {
                    // 出现过就进行合并操作，这里合并操作操作的是行与行之间
                    unionFind.Merge(strMap[accounts[i][j]], i);
                }
            }
        }

        vector<vector<string>> result;
        // 这里保存的是函数和账号，注意的是拥有相同账号的函数会被合并在一起
        unordered_map<int, vector<string>> intMap;
        for (const auto &i : strMap) {
            // 合并账号
            intMap[unionFind.Find(i.second)].emplace_back(i.first);
        }

        for (auto &i : intMap) {
            vector<string> tmpVec;
            tmpVec.emplace_back(accounts[i.first][0]);
            sort(i.second.begin(), i.second.end());
            tmpVec.insert(tmpVec.end(), i.second.begin(), i.second.end());
            result.emplace_back(tmpVec);
        }

        return result;
    }
};

int main()
{
    vector<vector<string>> accounts = {{"John", "johnsmith@mail.com", "john00@mail.com"}, {"John", "johnnybravo@mail.com"}, {"John", "johnsmith@mail.com", "john_newyork@mail.com"}, {"Mary", "mary@mail.com"}};
    auto result = Solution::accountsMerge(accounts);
    for (const auto &i : result) {
        for (const auto &j : i) {
            cout << j << ' ';
        }

        cout << endl;
    }

    return 0;
}

#include <vector>
#include <queue>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    static int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
    {
        if (source == target) {
            return 0;
        }

        int routeSize = static_cast<int>(routes.size());
        // 记录站点出现在那些线路上
        unordered_map<int, vector<int>> routeMap;
        for (int i = 0; i < routeSize; ++i) {
            for (int j = 0; j < routes[i].size(); ++j) {
                // i为出现的公交路线
                routeMap[routes[i][j]].emplace_back(i);
            }
        }

        // 每一层需要遍历的站点，这里需要注意的是遍历的是站点不是公交线路
        queue<int> numQueue;
        numQueue.push(source);
        // 记录访问过的公交线路
        vector<bool> visitedVec(routeSize + 1, false);
        int level = 0;

        while (!numQueue.empty()) {
            int numQueueSize = static_cast<int>(numQueue.size());
            level++;
            while (numQueueSize > 0) {
                // currNum是当前遍历的站点
                int currNum = numQueue.front();
                numQueue.pop();
                // 遍历该站点出现在那几条公交线路上
                for (const auto &circuit : routeMap[currNum]) {
                    if (visitedVec[circuit]) {
                        continue;
                    }

                    // 遍历该条公交线路上的所有站点
                    for (const int route : routes[circuit]) {
                        if (route == target) {
                            return level;
                        }

                        numQueue.push(route);
                    }

                    visitedVec[circuit] = true;
                }

                numQueueSize--;
            }
        }

        return -1;
    }
};

int main()
{
    vector<vector<int>> routes = {{1,2,7},{3,6,7}};
    int source = 1;
    int target = 6;

    cout << Solution::numBusesToDestination(routes, source, target) << endl;
}

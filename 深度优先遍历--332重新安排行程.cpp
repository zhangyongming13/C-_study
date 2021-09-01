#include <vector>
#include <map>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    static vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        // key为出发点，value中first是目的地second为本路线的次数
        // 使用map不使用unorder_map确保字典序小的在前面保证字典序小的路径先选到
        map<string, map<string, int>> ticketsMap;
        for (const auto &ticket : tickets) {
            ticketsMap[ticket[0]][ticket[1]]++;
        }

        vector<string> result{"JFK"};
        if (Dfs(ticketsMap, result, static_cast<int>(tickets.size()))) {
            return result;
        }

        return {};
    }

private:
    static bool Dfs(map<string, map<string, int>> &ticketMap, vector<string> &result, int ticketSize)
    {
        if (result.size() == (ticketSize + 1)) {
            return true;
        }

        for (auto &destMap : ticketMap[*(--result.end())]) {
            if (destMap.second > 0) {
                // 回溯算法，如果这条路径到不了就进行回溯
                destMap.second--;
                result.emplace_back(destMap.first);
                if (Dfs(ticketMap, result, ticketSize)) {
                    // 标识选择这一条路径可以到达
                    return true;
                }
                destMap.second++;
                result.pop_back();
            }
        }

        return false;
    }
};

int main()
{
    vector<vector<string>> tickets = {{"MUC","LHR"},{"JFK","MUC"},{"SFO","SJC"},{"LHR","SFO"}};
    auto result = Solution::findItinerary(tickets);
    for (const auto &str : result) {
        cout << str << ' ';
    }

    return 0;
}

#include <vector>
#include <iostream>

// https://leetcode-cn.com/problems/gas-station/submissions/

using namespace std;

// 暴力破解法
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int flag = 0;
        for (int start = 0; start < gas.size(); ++start) {
            int carPlace = start;
            int gasCount = 0;
            do {
                gasCount += gas[carPlace];
                if (0 > (gasCount - cost[carPlace])) {
                    flag = -1;
                    break;
                }
                gasCount -= cost[carPlace];
                if ((carPlace + 1) >= gas.size()) {
                    carPlace = 0;
                } else {
                    carPlace++;
                }
            } while (carPlace != start);
            if (flag == 0) {
                return start;
            }
            flag = 0;
        }
        return -1;
    }
};

// 一次遍历法。首先算出加的油的量和消耗油的量的差，如果这个值小于0，那么无论从哪里出发都不能完成环绕的任务
// 如果大于或等于0，就要计算出发的点了。假设从编号为0站开始，一直到k站都正常，在开往k+1站时车子没油了。这时，应该将起点设置为k+1站。
// 因为k->k+1站耗油太大，0->k站剩余油量都是不为负的，每减少一站，就少了一些剩余油量。所以如果从k前面的站点作为起始站，剩余油量不可能冲过k+1站。
class Solution_1 {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalSurplusGas = 0;
        int surplusGas = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); ++i) {
            totalSurplusGas += gas[i] - cost[i];
            surplusGas += gas[i] - cost[i];
            if (0 > surplusGas) {
                start = i + 1;
                surplusGas = 0;
            }
        }

        if (0 > totalSurplusGas) {
            return -1;
        } else {
            return start;
        }
    }
};

int main()
{
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};
    Solution_1 solution;
    cout << solution.canCompleteCircuit(gas, cost);
}
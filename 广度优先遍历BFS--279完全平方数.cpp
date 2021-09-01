#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    static int numSquares(int n)
    {
        vector<int> squaresVec;
        GenSquaresVec(n, squaresVec);

        // 用来保存每一层需要遍历的节点
        queue<int> numQueue;
        numQueue.push(n);
        // 存储遍历过的节点
        vector<bool> visitedVec(n + 1, false);
        int level = 0;
        while (!numQueue.empty()) {
            level++;
            // 记录这一层需要遍历的元素个数，后面从队列中取出
            int numQueueLen = static_cast<int>(numQueue.size());
            while (numQueueLen > 0) {
                int currNum = numQueue.front();
                numQueue.pop();
                for (const auto squares : squaresVec) {
                    int next = currNum - squares;
                    if (next < 0) {
                        break;
                    } else if (next == 0) {
                        return level;
                    } else {
                        // 该元素已经遍历过了，证明有更好的squares更快的到达，所以丢列就不添加这个next了
                        if (visitedVec[next]) {
                            continue;
                        }

                        numQueue.push(next);
                        visitedVec[next] = true;
                    }
                }

                numQueueLen--;
            }
        }

        return n;
    }

    static void GenSquaresVec(int n, vector<int> &squaresVec)
    {
        int start = 1;
        int diff = 3;
        while (start <= n) {
            squaresVec.emplace_back(start);
            start += diff;
            diff += 2;
        }
    }
};

int main()
{
    int n = 13;
    cout << Solution::numSquares(n) << endl;

    return 0;
}
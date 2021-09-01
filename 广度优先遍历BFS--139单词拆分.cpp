#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    static bool wordBreak(string s, vector<string> &wordDict)
    {
        queue<int> indexQueue;
        indexQueue.push(0);

        int strSize = static_cast<int>(s.size());
        // 记录哪些左结点被访问过了
        vector<bool> visitedVec(strSize + 1, false);
        visitedVec[0] = true;

        while (!indexQueue.empty()) {
            int indexQueueSize = static_cast<int>(indexQueue.size());
            while (indexQueueSize > 0) {
                int currIndex = indexQueue.front();
                indexQueue.pop();
                for (int i = (currIndex + 1); i <= strSize; ++i) {
                    if (visitedVec[i]) {
                        continue;
                    }

                    // 截取字符串看是否出现在字典中
                    string tmpStr = s.substr(currIndex, i - currIndex);
                    if (find(wordDict.begin(), wordDict.end(), tmpStr) != wordDict.end()) {
                        if (i == strSize) {
                            return true;
                        }

                        indexQueue.push(i);
                        visitedVec[i] = true;
                    }
                }

                indexQueueSize--;
            }
        }

        return false;
    }
};


int main()
{
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    cout << Solution::wordBreak(s, wordDict) << endl;
}

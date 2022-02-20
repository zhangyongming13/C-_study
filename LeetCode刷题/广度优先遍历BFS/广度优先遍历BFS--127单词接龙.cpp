#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    static int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return 0;
        }

        // 记录每一层需要遍历的元素
        queue<string> strQueue1;
        strQueue1.push(beginWord);
        // 记录已经遍历过的元素
        int wordListSize = static_cast<int>(wordList.size());
        vector<bool> visitedVec(wordListSize, false);
        int level = 0;
        while (!strQueue1.empty()) {
            level++;
            // 记录当前层数需要遍历的元素个数
            int strQueue1Len = static_cast<int>(strQueue1.size());
            while (strQueue1Len > 0) {
                string currStr = strQueue1.front();
                strQueue1.pop();
                if (currStr == endWord) {
                    return level;
                }

                for (int i = 0; i < wordListSize; ++i) {
                    if (visitedVec[i]) {
                        continue;
                    }

                    // 如果仅相差一个字符就添加到下一层遍历中，并且标记为已遍历
                    if (IsDiffOneChar(wordList[i], currStr)) {
                        visitedVec[i] = true;
                        strQueue1.push(wordList[i]);
                    }
                }

                strQueue1Len--;
            }
        }

        return 0;
    }

    // 判断是否相差一个字符
    static bool IsDiffOneChar(const string &str1, const string &str2)
    {
        int diffCount = 0;
        int strLen = static_cast<int>(str1.size());
        for (int i = 0; i < strLen; ++i) {
            if (str1[i] != str2[i]) {
                diffCount++;

                if (diffCount >= 2) {
                    return false;
                }
            }
        }

        return diffCount == 1;
    }
};

int main()
{
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    cout << Solution::ladderLength(beginWord, endWord, wordList) << endl;

    return 0;
}

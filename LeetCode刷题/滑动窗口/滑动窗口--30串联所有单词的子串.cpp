#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    static vector<int> findSubstring(string s, vector<string>& words)
    {
        // 这里需要注意的是每个单词的长度都是一样的，所以滑动窗口的大小是一致的，这样题目就很好解决
        int signalWordLen = static_cast<int>(words[0].size());
        int wordsLen = signalWordLen * static_cast<int>(words.size());
        vector<int> result;

        // 记录要查找的字串情况
        map<string, int> wordMap;
        for (const auto &word : words) {
            wordMap[word]++;
        }

        for (int left = 0; (left + wordsLen) <= s.size(); ++left) {
            // 截取固定窗口大小的字符进行判断
            string tmpStr = s.substr(left, wordsLen);
            int tmpLeft = 0;
            map<string, int> tmpMap;
            // 遍历窗口字符
            while (tmpLeft < wordsLen) {
                string word = tmpStr.substr(tmpLeft, signalWordLen);
                if (wordMap.count(word) == 0) {
                    break;
                }

                tmpMap[word]++;
                tmpLeft += signalWordLen;
            }

            // 判断是否相等
            if (IsSameMap(tmpMap, wordMap)) {
                result.emplace_back(left);
            }
        }

        return result;
    }

private:
    static bool IsSameMap(const map<string, int> &map1, const map<string, int> &map2)
    {
        if (map1.size() != map2.size()) {
            return false;
        }

        auto iter1 = map1.begin();
        auto iter2 = map2.begin();
        for (; iter1 != map1.end(); ++iter1, ++iter2) {
            if ((iter1->first != iter2->first) || (iter1->second != iter2->second)) {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    string s = "barfoofoobarthefoobarman";
    vector<string> words = {"bar","foo","the"};
    auto result = Solution::findSubstring(s, words);
    for (auto i : result) {
        cout << i << ' ';
    }

    return 0;
}

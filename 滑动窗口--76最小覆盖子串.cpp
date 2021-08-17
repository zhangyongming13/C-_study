#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    static string minWindow(string s, string t)
    {
        unordered_map<char, int> needs;
        unordered_map<char, int> windows;
        // 记录需要匹配字符串的情况
        for (const auto &i : t) {
            needs[i]++;
        }

        int left = 0;
        // 记录最小字串开始的位置，结合minLen得到最小字串
        int resultStart = 0;
        int sSize = static_cast<int>(s.size());
        int minLen = sSize + 1;
        int matchTimes = 0;
        for (int right = 0; right < sSize; ++right) {
            if (needs.count(s[right]) != 0) {
                windows[s[right]]++;

                // 需要注意的是这里只有相等的时候才可以匹配次数++，因为会存在大于的情况，这时只是单个字符超过了而已并不是真正的匹配上
                if (windows[s[right]] == needs[s[right]]) {
                    matchTimes++;
                }
            }

            // 匹配上之后开始移动左边界，找到最小的字串
            while (matchTimes == needs.size()) {
                if (minLen > (right - left)) {
                    resultStart = left;
                    minLen = right - left;
                }

                if (needs.count(s[left]) != 0) {
                    windows[s[left]]--;

                    if (windows[s[left]] < needs[s[left]]) {
                        matchTimes--;
                    }
                }

                left++;
            }
        }

        return (minLen == (sSize + 1)) ? "" : s.substr(resultStart, minLen + 1);
    }
};

int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";
    auto result = Solution::minWindow(s, t);
    cout << result << endl;

    return 0;
}

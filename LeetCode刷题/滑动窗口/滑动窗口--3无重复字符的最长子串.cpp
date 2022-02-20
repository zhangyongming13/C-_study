#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    static int lengthOfLongestSubstring(string s)
    {
        vector<char> charVec;
        int result = 0;
        int left = 0;
        for (int right = 0; right < s.size(); ++right) {
            auto iter = find(charVec.begin(), charVec.end(), s[right]);
            // 有重复元素的时候，左指针向右移动
            while (iter != charVec.end()) {
                // 左指针向右移的时候，删除的元素肯定是charVec的第一个元素
                charVec.erase(charVec.begin());
                left++;
                // charVec的第一个元素不一定就是重复元素，所以需要添加判断
                iter = find(charVec.begin(), charVec.end(), s[right]);
            }

            result = max(result, right - left + 1);
            charVec.emplace_back(s[right]);
        }

        return result;
    }
};

int main()
{
    string s = "abcabcbb";
    auto result = Solution::lengthOfLongestSubstring(s);
    cout << result << endl;

    return 0;
}

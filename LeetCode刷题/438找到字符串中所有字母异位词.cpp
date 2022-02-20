#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    static vector<int> findAnagrams(const string& s, const string& p) {
        vector<int> result;
        unordered_map<char, int> needs;
        unordered_map<char, int> windows;
        for (auto i : p) {
            needs[i]++;
        }

        int left = 0;
        int right = 0;
        int matchTimes = 0;

        while (right < s.size()) {
            if (needs.count(s[right])) {
                windows[s[right]]++;

                if (windows[s[right]] == needs[s[right]]) {
                    matchTimes++;
                }
            }

            while (matchTimes == needs.size()) {
                if ((right - left) == (p.size() - 1)) {
                    result.emplace_back(left);
                }

                if (needs.count(s[left])) {
                    windows[s[left]]--;

                    if (windows[s[left]] < needs[s[left]]) {
                        matchTimes--;
                    }
                }
                left++;
            }

            right++;
        }

        return result;
    }
};

int main()
{
    string s = "abaacbabc";
    string p = "abc";
    auto result = Solution::findAnagrams(s, p);
    for (auto i : result) {
        cout << i << ' ';
    }

    return 0;
}

#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    static vector<string> findRepeatedDnaSequences(string s)
    {
        unordered_map<string, int> strMap;
        const int strLength = 10;
        for (int i = 0; (i + strLength) <= s.size(); ++i) {
            strMap[s.substr(i, strLength)]++;
        }

        vector<string> result;
        for (const auto &i : strMap) {
            if (i.second >= 2) {
                result.emplace_back(i.first);
            }
        }

        return result;
    }
};

int main()
{
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    auto  result = Solution::findRepeatedDnaSequences(s);
    for (const auto &i : result) {
        cout << i << endl;
    }

    return 0;
}

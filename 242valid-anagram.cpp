#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        // 使用hash映射的方式S负责加，T负责减
        vector<int> sVec(26, 0);
        for (unsigned int i = 0; i < s.size(); ++i) {
            sVec[s[i] - 'a']++;
            sVec[t[i] - 'a']--;
        }
        // 最终的hash表中如果存在不为0的元素，则不是字母异位词
        for (auto i : sVec) {
            if (i != 0) {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution solution;
    string S = "a";
    string T = "b";
    if (solution.isAnagram(S, T)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
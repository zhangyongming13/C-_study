#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    static int balancedStringSplit(const string &s)
    {
        int result = 0;
        int lCount = 0;
        int rCount = 0;
        for (const auto chr : s) {
            if ((lCount == rCount) && (lCount != 0)) {
                result++;
                lCount = 0;
                rCount = 0;
            }

            if (chr == 'L') {
                lCount++;
            } else if (chr == 'R') {
                rCount++;
            }
        }

        return lCount == rCount ? result + 1 : result;
    }
};

int main()
{
    string s = "RLRRLLRLRL";
    cout << Solution::balancedStringSplit(s) << endl;

    return 0;
}

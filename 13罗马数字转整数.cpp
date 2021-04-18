#include <string>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    Solution() {
        romaNumberMap['I'] = 1;
        romaNumberMap['V'] = 5;
        romaNumberMap['X'] = 10;
        romaNumberMap['L'] = 50;
        romaNumberMap['C'] = 100;
        romaNumberMap['D'] = 500;
        romaNumberMap['M'] = 1000;
    }

    int romanToInt(const string& s) {
        int result = 0;
        if (s.empty()) {
            return result;
        }

        for (unsigned int i = 0; i < s.size(); ++i) {
            if ((s[i] == 'I') || (s[i] == 'X') || (s[i] == 'C')) {
                getValue(s, result, i);
                continue;
            }

            result += romaNumberMap[s[i]];
        }

        return result;
    }

    static bool makeUp(char inputCharA, char inputCharB) {
        switch (inputCharA) {
            case 'I':
                if ((inputCharB == 'V') || (inputCharB == 'X')) {
                    return true;
                }
                break;

            case 'X':
                if ((inputCharB == 'L') || (inputCharB == 'C')) {
                    return true;
                }
                break;

            case 'C':
                if ((inputCharB == 'D') || (inputCharB == 'M'))
                    return true;
                break;

            default:
                return false;
        }

        return false;
    }

    void getValue(const string &s, int &result, unsigned int &i){
        if ((i + 1) < s.size()) {
            if (makeUp(s[i], s[i + 1])) {
                result += romaNumberMap[s[i + 1]] - romaNumberMap[s[i]];
                i++;
            } else {
                result += romaNumberMap[s[i]];
            }
        } else {
            result += romaNumberMap[s[i]];
        }
    }

private:
    map<char, int> romaNumberMap;
};

int main()
{
    string s = "DCXXI";
    Solution solution;
    cout << solution.romanToInt(s) << endl;
    return 0;
}

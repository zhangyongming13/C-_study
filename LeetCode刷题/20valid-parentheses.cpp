#include <string>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    static  bool signalIsValid(stack<char> &tmpStack, char inputChar) {
        if (tmpStack.empty()) {
            return false;
        } else if (inputChar != tmpStack.top()) {
            return false;
        }
        return true;
    }

    static bool isValid(const string& s) {
        stack<char> tmpStack;
        for (auto i : s) {
            if (')' == i) {
                if (signalIsValid(tmpStack, '(')) {
                    tmpStack.pop();
                    continue;
                }
                return false;
            } else if ('}' == i) {
                if (signalIsValid(tmpStack, '{')) {
                    tmpStack.pop();
                    continue;
                }
                return false;
            } else if (']' == i) {
                if (signalIsValid(tmpStack, '[')) {
                    tmpStack.pop();
                    continue;
                }
                return false;
            } else {
                tmpStack.push(i);
            }
        }
        if (tmpStack.empty()) {
            return true;
        }
        return false;
    }
};

int main()
{
    string inputStr = "()";
    if (Solution::isValid(inputStr)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
}

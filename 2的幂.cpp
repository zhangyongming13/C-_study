#include <iostream>

using namespace std;

class Solution {
public:
    static bool isPowerOfTwo(int n) {
        while (n != 0) {
            if (n == 1) {
                return true;
            }

            if ((n % 2) != 0) {
                return false;
            }

            n /= 2;
        }

        return false;
    }
};

int main()
{
    if (Solution::isPowerOfTwo(3)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

#include <iostream>

using namespace std;

class Solution {
public:
    static int xorOperation(int n, int start)
    {
        if (n <= 0) {
            return 0;
        }

        int result = start;
        for (int i = 1; i < n; ++i) {
            int tmp = start + 2 * i;
            result ^= tmp;
        }

        return result;
    }
};

int main()
{
    int n = 5;
    int start = 0;
    cout << Solution::xorOperation(n, start) << endl;

    return 0;
}

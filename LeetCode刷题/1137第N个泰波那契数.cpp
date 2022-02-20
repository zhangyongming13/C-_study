#include <iostream>

using namespace std;

class Solution {
public:
    static int tribonacci(int n)
    {
        if (n == 0) {
            return 0;
        } else if ((n == 1) || (n == 2)) {
            return 1;
        }

        int t0 = 0;
        int t1 = 1;
        int t2 = 1;
        int result = 0;
        for (int i = 3; i <= n; ++i) {
            result = t0 + t1 + t2;
            t0 = t1;
            t1 = t2;
            t2 = result;
        }

        return result;

    }
};

int main()
{
    auto result = Solution::tribonacci(37);
    cout << result << endl;

    return 0;
}

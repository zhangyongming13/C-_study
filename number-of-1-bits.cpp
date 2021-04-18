#include <cstdint>
#include <iostream>

// https://leetcode-cn.com/problems/number-of-1-bits/

using namespace std;

class Solution {
public:
    static int hammingWeight(uint32_t n) {
        int result = 0;
        while (n != 0) {
            result += n % 2;
            n = n >> 1;
        }

        return result;
    }
};

int main()
{
    uint32_t n = 00000000000000000000000000001011;
    cout << Solution::hammingWeight(n) << endl;
}

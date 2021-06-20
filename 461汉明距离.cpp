#include <iostream>

using namespace std;

class Solution {
public:
    static int hammingDistance(int x, int y) {
        int result = 0;

        for (int i = 31; i >= 0; --i) {
            if (((x >> i) & 1) != ((y >> i) & 1)) {
                result++;
            }
        }

        return result;
    }
};

int main()
{
    int x = 1;
    int y = 4;
    cout <<  Solution::hammingDistance(1, 4);
}

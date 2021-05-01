#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    static int shipWithinDays(vector<int>& weights, int D) {
        int maxValue = 0;
        int sumValue = 0;
        GetMaxAndSum(weights, maxValue, sumValue);

        for (int result = maxValue; result <= sumValue; ++result) {
            if (Verification(weights, result, D)) {
                return result;
            }
        }

        return sumValue;
    }

private:
    static void GetMaxAndSum(vector<int> &weight, int &maxValue, int &sumValue) {
        for (auto i : weight) {
            if (i > maxValue) {
                maxValue = i;
            }

            sumValue += i;
        }
    }

    static bool Verification(vector<int> &weight, int result, int D) {
        int signalWeight = 0;
        int day = 1;
        for (int i : weight) {
            signalWeight += i;
            // 货的重量超过单次运载量之后，先运走之前的，保留本次的继续
            if (signalWeight > result) {
                day++;
                signalWeight = i;
            }

            if (day > D) {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    int D = 5;
    cout << Solution::shipWithinDays(weights, D) << endl;

    return 0;
}

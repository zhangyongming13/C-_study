#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    static int numRescueBoats(vector<int> &people, int limit)
    {
        int peopleSize = static_cast<int>(people.size());
        int result = 0;
        int left = 0;
        int right = peopleSize - 1;

        sort(people.begin(), people.end());
        while (left <= right) {
            if ((people[left] + people[right]) <= limit) {
                left++;
            }

            right--;
            result++;
        }

        return result;
    }
};

int main()
{
    vector<int> people = {3,2,2,1};
    int limit = 3;
    cout << Solution::numRescueBoats(people, limit) << endl;

    return 0;
}

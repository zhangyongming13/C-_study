#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <iostream>

using namespace std;

class Solution {
public:
    static string largestNumber(vector<int>& nums) {
        vector<string> numsString;
        numsString.reserve(nums.size());
        for (auto i : nums) {
            numsString.emplace_back(to_string(i));
        }

        // 给sort函数传递第三个参数自定义的比较函数
        sort(numsString.begin(), numsString.end(), cmp);

        stringstream ss;
        for (const auto& i : numsString) {
            ss << i;
        }

        string result = ss.str();

        if (result[0] == '0') {
            return "0";
        }

        return result;
    }

private:
    static bool cmp(const string& strA, const string& strB) {
        return (strA + strB) > (strB + strA);
    }
};

int main()
{
    vector<int> nums = {3,30,34,5,9};
    cout << Solution::largestNumber(nums) << endl;
}

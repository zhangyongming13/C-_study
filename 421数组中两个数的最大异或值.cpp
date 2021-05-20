#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// 暴力解法，超时
//class Solution {
//public:
//    static int findMaximumXOR(vector<int>& nums)
//    {
//        int result = 0;
//        unsigned int numsLength = nums.size();
//        if (numsLength <= 1) {
//            return result;
//        }
//
//        for (unsigned int i = 0; i < (numsLength - 1); ++i) {
//            for (unsigned int j = (i + 1); j < numsLength; ++j) {
//                int tmpNum = nums[i] ^ nums[j];
//                if (tmpNum > result) {
//                    result = tmpNum;
//                }
//            }
//        }
//
//        return result;
//    }
//};

// 前缀数解法
class Trie {
public:
    Trie() = default;

    void Insert(int x)
    {
        Trie *root = this;
        for (int i = 30; i >= 0; --i) {
            // 从高位到低位构建trie前缀树
            int tmp = (x >> i) & 1;
            if (!root->next[tmp]) {
                root->next[tmp] = new Trie();
            }

            root = root->next[tmp];
        }
    }

    int Search(int x)
    {
        Trie *root = this;
        int result = 0;

        for (int i = 30; i >= 0; --i) {
            int tmp = (x >> i) & 1;
            if (root->next[!tmp]) {
                root = root->next[!tmp];
                result = result * 2 + !tmp;
            } else {
                root = root->next[tmp];
                result = result * 2 + tmp;
            }
        }

        result ^= x;

        return result;
    }

private:
    Trie *next[2] = {nullptr};
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie *root = new Trie();
        for (auto number : nums) {
            root->Insert(number);
        }

        int result = 0;
        for (auto number : nums) {
            result = max(result, root->Search(number));
        }

        return result;
    }
};

int main()
{
    vector<int> nums = {3,10,5,25,2,8};
    Solution solution;
    cout << solution.findMaximumXOR(nums) << endl;

    return 0;
}

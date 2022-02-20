#include<iostream>
#include<algorithm>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    static vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, unsigned int> wordMap;
        for (const auto &word : words) {
            wordMap[word]++;
        }

        vector<pair<string, unsigned int>> wordVec;
        wordVec.reserve(wordMap.size());
        for (const auto& item : wordMap) {
            wordVec.emplace_back(item.first, item.second);
        }

        // 自定义排序
        sort(wordVec.begin(), wordVec.end(), cmp);

        vector<string> result;
        result.reserve(k);
        for (int i = 0; i < k; ++i) {
            result.emplace_back(wordVec[i].first);
        }

        return result;
    }

private:
    // 自定义sort排序比较函数
    static bool cmp(const pair<string, unsigned int>& pairA, const pair<string, unsigned int>& pairB) {
        if (pairA.second != pairB.second) {
            return pairA.second > pairB.second;
        } else {
            return pairA.first < pairB.first;
        }
    }
};

int main()
{
    vector<string> words = {"glarko","zlfiwwb","nsfspyox","pwqvwmlgri","qggx","qrkgmliewc","zskaqzwo","zskaqzwo","ijy","htpvnmozay","jqrlad","ccjel","qrkgmliewc","qkjzgws","fqizrrnmif","jqrlad","nbuorw","qrkgmliewc","htpvnmozay","nftk","glarko","hdemkfr","axyak","hdemkfr","nsfspyox","nsfspyox","qrkgmliewc","nftk","nftk","ccjel","qrkgmliewc","ocgjsu","ijy","glarko","nbuorw","nsfspyox","qkjzgws","qkjzgws","fqizrrnmif","pwqvwmlgri","nftk","qrkgmliewc","jqrlad","nftk","zskaqzwo","glarko","nsfspyox","zlfiwwb","hwlvqgkdbo","htpvnmozay","nsfspyox","zskaqzwo","htpvnmozay","zskaqzwo","nbuorw","qkjzgws","zlfiwwb","pwqvwmlgri","zskaqzwo","qengse","glarko","qkjzgws","pwqvwmlgri","fqizrrnmif","nbuorw","nftk","ijy","hdemkfr","nftk","qkjzgws","jqrlad","nftk","ccjel","qggx","ijy","qengse","nftk","htpvnmozay","qengse","eonrg","qengse","fqizrrnmif","hwlvqgkdbo","qengse","qengse","qggx","qkjzgws","qggx","pwqvwmlgri","htpvnmozay","qrkgmliewc","qengse","fqizrrnmif","qkjzgws","qengse","nftk","htpvnmozay","qggx","zlfiwwb","bwp","ocgjsu","qrkgmliewc","ccjel","hdemkfr","nsfspyox","hdemkfr","qggx","zlfiwwb","nsfspyox","ijy","qkjzgws","fqizrrnmif","qkjzgws","qrkgmliewc","glarko","hdemkfr","pwqvwmlgri"};
    int k = 14;
    auto result = Solution::topKFrequent(words, k);
    for (const auto& item : result) {
        cout << item << ' ';
    }

    return 0;
}

#include <set>
#include <string>
#include <algorithm>

using namespace std;

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() = default;

    /** Inserts a word into the trie. */
    void insert(const string& word) {
        trieSet.insert(word);
    }

    /** Returns if the word is in the trie. */
    bool search(const string& word) {
        auto result = find(trieSet.cbegin(), trieSet.cend(), word);
        return !(result == trieSet.cend());
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(const string& prefix) {
        for (const auto& word : trieSet) {
            if (prefix.size() > word.size()) {
                continue;
            }

            string tmpStr = word.substr(0, prefix.size());
            if (tmpStr == prefix) {
                return true;
            }
        }

        return false;
    }

private:
    set<string> trieSet;
};

int main()
{
    Trie trie = *new Trie();
    trie.insert("apple");
    trie.search("apple");   // 返回 True
    trie.search("app");     // 返回 False
    trie.startsWith("app"); // 返回 True
    trie.insert("app");
    trie.search("app");     // 返回 True
}

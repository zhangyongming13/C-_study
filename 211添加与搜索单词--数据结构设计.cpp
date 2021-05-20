#include <string>

using namespace std;

class Trie {
public:
    void AddWord(const string &word)
    {
        Trie *root = this;
        for (auto signalChar : word) {
            if (!root->next[signalChar - 'a']) {
                root->next[signalChar - 'a'] = new Trie();
            }

            root = root->next[signalChar - 'a'];
        }

        root->isEnd = true;
    }

    bool SearchWordTrace(int index, Trie *root, const string &word)
    {
        // 匹配长度和isEnd都结束了才算匹配上
        if (index == word.size()) {
            return root->isEnd;
        }

        if (word[index] == '.') {
            // 所有可能的分支都需要走一遍
            for (auto & i : root->next) {
                if (i && SearchWordTrace(index + 1, i, word)) {
                    return true;
                }
            }
        } else {
            if (root->next[word[index] - 'a'] == nullptr) {
                return false;
            }

            return SearchWordTrace(index + 1, root->next[word[index] - 'a'], word);
        }

        return false;
    }

    bool SearchWord(const string &word)
    {
        Trie *root = this;
        return SearchWordTrace(0, root, word);
    }

private:
    bool isEnd = false;
    Trie *next[26] = {nullptr};
};

class WordDictionary {
public:
    Trie *root = new Trie();
    /** Initialize your data structure here. */
    WordDictionary() = default;

    void addWord(const string& word) const {
        root->AddWord(word);
    }

    bool search(const string& word) const {
        return root->SearchWord(word);
    }
};
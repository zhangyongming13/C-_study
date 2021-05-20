class Trie {
private:
    int keyValue = 0;
    Trie *next[26] = {nullptr};
    map<string, int> prefixMap;

public:
    void Insert(const string &key, int val)
    {
        Trie *root = this;
        bool changeFlag = false;
        int oldValue = 0;
        // 更新val的情况，目前没想到好的办法
        if (prefixMap.count(key) == 1) {
            if (prefixMap[key] == val) {
                return;
            }

            changeFlag = true;
            oldValue = prefixMap[key];
            prefixMap[key] = val;
        } else {
            prefixMap[key] = val;
        }

        for (auto signalChar : key) {
            if (root->next[signalChar - 'a']) {
                if (changeFlag) {
                    root->next[signalChar - 'a']->keyValue -= oldValue;
                }

                root->next[signalChar - 'a']->keyValue += val;
            } else {
                root->next[signalChar - 'a'] = new Trie();
                root->next[signalChar - 'a']->keyValue = val;
            }

            root = root->next[signalChar - 'a'];
        }
    }

    int GetSum(const string &prefix)
    {
        int result = 0;
        Trie *root = this;
        unsigned int prefixLen = prefix.size();
        unsigned int index = 0;
        for (;index < prefixLen; ++index) {
            if (!root->next[prefix[index] - 'a']) {
                break;
            }

            result = root->next[prefix[index] - 'a']->keyValue;
            root = root->next[prefix[index] - 'a'];
        }

        // prefix没有被完全匹配上，直接返回0
        if (index != prefixLen) {
            return 0;
        }

        return result;
    }
};

class MapSum {
public:
    Trie *root = new Trie();
    /** Initialize your data structure here. */
    MapSum() = default;

    void insert(const string &key, int val) const {
        root->Insert(key, val);
    }

    int sum(const string &prefix) const {
        return root->GetSum(prefix);
    }
};

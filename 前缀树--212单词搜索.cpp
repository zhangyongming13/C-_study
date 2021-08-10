#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Trie {
private:
    string word;
    Trie *next[26] = {nullptr};
    vector<vector<char>> board;
    vector<string> result;
    int xLen = 0;
    int yLen = 0;

public:
    void Insert(const string &insertWord)
    {
        Trie *root = this;
        for (auto signalChar : insertWord) {
            if (!root->next[signalChar - 'a']) {
                root->next[signalChar - 'a'] = new Trie();
            }

            root = root->next[signalChar - 'a'];
        }

        root->word = insertWord;
    }

    void searchTrace(int x, int y, Trie *root)
    {
        if ((x < 0) || (x >= xLen) || (y < 0) || (y >= yLen)) {
            return;
        }

        char tmpChar = board[x][y];
        if (tmpChar == '.') {
            return;
        }

        if (root->next[tmpChar - 'a'] == nullptr) {
            return;
        }

        if (!root->next[tmpChar - 'a']->word.empty()) {
            // 这里不结束的原因是后面可能还会有更长的匹配上的字符串 比如oath和oathf
            result.push_back(root->next[tmpChar - 'a']->word);
            root->next[tmpChar - 'a']->word = "";
        }

        // 回溯算法计算该点上下左右相邻结点
        board[x][y] = '.';
        searchTrace(x - 1, y, root->next[tmpChar - 'a']);
        searchTrace(x + 1, y, root->next[tmpChar - 'a']);
        searchTrace(x, y + 1, root->next[tmpChar - 'a']);
        searchTrace(x, y - 1, root->next[tmpChar - 'a']);
        board[x][y] = tmpChar;

    }

    vector<string> search(vector<vector<char>>& inputBoard)
    {
        board = inputBoard;
        Trie *root = this;
        xLen = board.size();
        yLen = board[0].size();
        for (int x = 0; x < xLen; ++x) {
            for (int y = 0; y < yLen; ++y) {
                searchTrace(x, y, root);
            }
        }

        return result;
    }
};

class Solution {
public:
    Trie *root = new Trie();

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) const {
        for (const auto &word : words) {
            root->Insert(word);
        }

        return root->search(board);
    }
};

int main()
{
    vector<vector<char>> board = {{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
    vector<string> words = {"oathf", "oath","pea","eat","rain"};
    Solution solution;
    auto result = solution.findWords(board, words);
    for (const auto& word : result) {
        cout << word << endl;
    }

    return 0;
}
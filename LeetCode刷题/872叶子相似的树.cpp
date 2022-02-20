#include <vector>
#include <deque>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2)
    {
        LevelTrace(root1, treeVal1);
        LevelTrace(root2, treeVal2);

        return treeVal1 == treeVal2;
    }

private:
    static void LevelTrace(TreeNode* root, vector<int> &treeVal)
    {
        if (root == nullptr) {
            return;
        }

        if ((root->left == nullptr) && (root->right == nullptr)) {
            treeVal.emplace_back(root->val);
        }

        if (root->left != nullptr) {
            LevelTrace(root->left, treeVal);
        }
        if (root->right != nullptr) {
            LevelTrace(root->right, treeVal);
        }
    }

private:
    vector<int> treeVal1;
    vector<int> treeVal2;
};
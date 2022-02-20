#include <vector>
#include <iostream>

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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum)
    {
        target = targetSum;
        if (root == nullptr) {
            return {};
        }

        vector<int> numVec;
        Dfs(root, numVec);

        return result;
    }

public:
    vector<vector<int>> result;
    int target = 0;

private:
    void Dfs(TreeNode *root, vector<int> &numVec)
    {
        if (root == nullptr) {
            return;
        }

        numVec.emplace_back(root->val);
        if ((root->right == nullptr) && (root->left == nullptr)) {
            int tmpSum = 0;
            for (const auto number : numVec) {
                tmpSum += number;
            }

            if (tmpSum == target) {
                result.emplace_back(numVec);
            }

            // 避免影响下一次回溯
            numVec.pop_back();
            return;
        }

        if (root->left != nullptr) {
            Dfs(root->left, numVec);
        }

        if (root->right != nullptr) {
            Dfs(root->right, numVec);
        }

        // 避免影响下一次回溯
        numVec.pop_back();
    }
};
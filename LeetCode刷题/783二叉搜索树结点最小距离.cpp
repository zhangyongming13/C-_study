#include <vector>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 需要注意的一点就是二叉搜索树中序遍历的时候得到的是一个升序的数组，利用这个特性解题
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        midTraver(root);

        if (result.empty() || (result.size() == 1)) {
            return 0;
        }

        int left = 0;
        int right = 1;
        long minDiff = INT64_MAX;
        while (right < result.size()) {
            if ((result[right] - result[left]) < minDiff) {
                minDiff = result[right] - result[left];
            }

            left = right;
            right++;
        }

        return int(minDiff);
    }

private:
    void midTraver(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        if (root->left != nullptr) {
            midTraver(root->left);
        }
        result.emplace_back(root->val);
        if (root->right != nullptr) {
            midTraver(root->right);
        }
    }

private:
    vector<int> result;
};

int main()
{
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    TreeNode node4(4);
    TreeNode node6(6);
    node2.left = &node1;
    node2.right = &node3;
    node4.left = &node2;
    node4.right = &node6;
    Solution solution;
    cout << solution.minDiffInBST(&node4) << endl;
    return 0;
}

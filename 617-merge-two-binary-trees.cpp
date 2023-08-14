// https://leetcode.cn/problems/merge-two-binary-trees/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode* ansRoot = nullptr;
        function<void(TreeNode*, TreeNode*, TreeNode*&)> dfs = [&](TreeNode* node1, TreeNode* node2, TreeNode*& cur) {
            if(node1 == nullptr && node2 == nullptr) {
                return;
            }
            else {
                int val1 = (node1 == nullptr ? 0 : node1->val);
                int val2 = (node2 == nullptr ? 0 : node2->val);
                int newVal = val1 + val2;

                cur = new TreeNode();
                cur->val = newVal;

                if(node1 == nullptr) {
                    dfs(nullptr, node2->left, cur->left);
                    dfs(nullptr, node2->right, cur->right);
                } else if(node2 == nullptr) {
                    dfs(node1->left, nullptr, cur->left);
                    dfs(node1->right, nullptr, cur->right);
                } else {
                    dfs(node1->left, node2->left, cur->left);
                    dfs(node1->right, node2->right, cur->right);
                }
            }
        };

        dfs(root1, root2, ansRoot);

        return ansRoot;
    }
};
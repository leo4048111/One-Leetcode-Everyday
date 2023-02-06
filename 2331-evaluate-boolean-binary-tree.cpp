// https://leetcode.cn/problems/evaluate-boolean-binary-tree/

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
    bool evaluateTree(TreeNode* root) {
        function<bool(TreeNode*)> dfs = [&](TreeNode* node) -> bool
        {
            if(node->left == nullptr && node->right == nullptr) return node->val;

            switch(node->val)
            {
                case 2:
                    return dfs(node->left) || dfs(node->right);
                case 3:
                    return dfs(node->left) && dfs(node->right);
                default: 
                    return false;
            } 
        };

        return dfs(root);
    }
};
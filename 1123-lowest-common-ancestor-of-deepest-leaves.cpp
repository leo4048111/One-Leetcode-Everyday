// https://leetcode.cn/problems/lowest-common-ancestor-of-deepest-leaves/description/?envType=daily-question&envId=2023-09-06

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
    int GetDepth(TreeNode* node) {
        if(node == nullptr) return 0;
        int l = GetDepth(node->left);
        int r = GetDepth(node->right);

        return max(l, r) + 1;
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int l = GetDepth(root->left);
        int r = GetDepth(root->right);

        if(l == r) return root;

        if(l > r) return lcaDeepestLeaves(root->left);

        return lcaDeepestLeaves(root->right);
    }
};
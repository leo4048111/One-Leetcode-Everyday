// https://leetcode.cn/problems/binary-tree-coloring-game/

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
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
       int lsize = 0, rsize = 0;

       function<int(TreeNode*)> dfs = [&](TreeNode* node) -> int{
            if(node == nullptr) return 0;

            int tmpL = dfs(node->left);
            int tmpR = dfs(node->right);

            if(node->val == x)
            {
                lsize = tmpL;
                rsize = tmpR;
            }

            return tmpL + tmpR + 1;
       };

       dfs(root);

       return max(max(lsize, rsize), n - 1 - lsize - rsize) > (n / 2);
    }
};
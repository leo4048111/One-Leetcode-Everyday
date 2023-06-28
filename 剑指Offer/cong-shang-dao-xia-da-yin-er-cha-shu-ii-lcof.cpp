// https://leetcode.cn/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;

        function<void(int, TreeNode*)> dfs = [&](int depth, TreeNode* node)
        {
            if(node == nullptr) return;
            if(res.size() == depth) {
                vector<int> x;
                x.push_back(node->val);
                res.push_back(x);
            } else {
                res[depth].push_back(node->val);
            }            

            dfs(depth + 1, node->left);
            dfs(depth + 1, node->right);
        };

        dfs(0, root);

        return res;
    }
};
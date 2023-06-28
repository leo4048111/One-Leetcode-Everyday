// https://leetcode.cn/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof/

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
    vector<int> levelOrder(TreeNode* root) {
        vector<int> ans;

        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty())
        {
            auto x = q.front();
            q.pop();
            if(x != nullptr)
            {
                ans.push_back(x->val);
                q.push(x->left);
                q.push(x->right);
            }
        }

        return ans;
    }
};
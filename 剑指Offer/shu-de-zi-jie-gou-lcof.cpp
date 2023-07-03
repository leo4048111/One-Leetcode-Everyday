// https://leetcode.cn/problems/shu-de-zi-jie-gou-lcof/

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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(B == nullptr) return false;
        function<bool(TreeNode*, TreeNode*)> dfs = [&](TreeNode* node, TreeNode* cmpNode) {
            if((node == nullptr) && (cmpNode == nullptr)) return true;

            if((node == nullptr) && (cmpNode != nullptr)) return false;

            if((node != nullptr) && (cmpNode == nullptr)) return true;

            if(node->val != cmpNode->val) return false;

            return dfs(node->left, cmpNode->left) && dfs(node->right, cmpNode->right);
        };

        stack<TreeNode*> s;
        s.push(A);
        bool res = false;
        while(s.size())
        {
            auto x = s.top();
            s.pop();
            if(dfs(x, B)) return true;
            if(x != nullptr)
            {
                s.push(x->left);
                s.push(x->right);
            }
        }

        return false;
    }
};
// https://leetcode.cn/problems/house-robber-iii/description/?envType=daily-question&envId=2023-09-18

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
class Solution
{
public:
    int rob(TreeNode *root)
    {
        function<pair<int, int>(TreeNode *)> dfs = [&](TreeNode *node) -> pair<int, int>
        {
            if (node == nullptr)
                return {0, 0};

            auto leftVal = dfs(node->left);
            auto rightVal = dfs(node->right);
            int robVal = node->val + leftVal.second + rightVal.second;
            int notRobVal = max(leftVal.first, leftVal.second) + max(rightVal.first, rightVal.second);

            return {robVal, notRobVal};
        };

        auto ans = dfs(root);

        return max(ans.first, ans.second);
    }
};
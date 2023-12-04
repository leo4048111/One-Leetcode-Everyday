// https://leetcode.cn/problems/binary-search-tree-to-greater-sum-tree/description/?envType=daily-question&envId=2023-12-04

class Solution
{
public:
    TreeNode *bstToGst(TreeNode *root)
    {
        function<int(TreeNode *, int)> dfs;
        dfs = [&](TreeNode *root, int val)
        {
            if (!root)
                return 0;
            int rightSum = dfs(root->right, val);
            rightSum += root->val;
            root->val = rightSum + val;
            rightSum += dfs(root->left, root->val);
            return rightSum;
        };

        dfs(root, 0);
        return root;
    }
};
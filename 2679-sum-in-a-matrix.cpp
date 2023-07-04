// https://leetcode.cn/problems/sum-in-a-matrix/

class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        for(auto & row : nums)
        {
            sort(row.begin(), row.end());
        }

        int res = 0;
        for(int j = 0; j < nums[0].size(); j++)
        {
            int foo = INT_MIN;
            for(int i = 0; i < nums.size(); i++)
            {
                foo = max(foo, nums[i][j]);
            }

            res += foo;
        }

        return res;
    }
};
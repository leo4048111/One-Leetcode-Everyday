// https://leetcode.cn/problems/minimum-falling-path-sum-ii/description/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 1) return grid[0][0];
        
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), INT_MAX));

        for(int i = 0; i < grid[0].size(); i++)
        {
            dp[0][i] = grid[0][i];
        }

        for(int i = 1; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                int minVal = INT_MAX;
                for(int k = 0; k < grid[i].size(); k++)
                {
                    if(k != j) {
                        minVal = min(minVal, dp[i - 1][k] + grid[i][j]);
                    }
                }
                dp[i][j] = minVal;
            }
        }

        int ans = INT_MAX;
        
        for(int i = 0; i < grid[grid.size() - 1].size(); i++)
        {
            ans = min(ans, dp[grid.size() - 1][i]);
        }

        return ans;
    }
};
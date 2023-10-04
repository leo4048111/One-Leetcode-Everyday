// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/description/?envType=daily-question&envId=2023-10-04

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(2, 0)));

        for(int i = 0; i < k; i++) {
            dp[0][i][1] = -prices[0];
        }

        for(int i = 1; i < n; i++) {
            dp[i][0][0] = max(dp[i - 1][0][0], dp[i - 1][0][1] + prices[i]);
            dp[i][0][1] = max(dp[i - 1][0][1], -prices[i]);

            for(int j = 1; j < k; j++) {
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
            }
        }

        return dp[n - 1][k - 1][0];
    }
};
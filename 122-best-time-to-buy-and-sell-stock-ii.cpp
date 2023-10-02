// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/?envType=daily-question&envId=2023-10-02

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int ans = 0;

        vector<vector<int>> dp(n, vector<int>(2, 0));

        dp[0][0] = -prices[0];
        dp[0][1] = 0;

        for(int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }

        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};
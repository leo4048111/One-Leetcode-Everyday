// https://leetcode.cn/problems/largest-sum-of-averages/

class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int K) {
        int n = nums.size();

        vector<double> sum(n + 1);
        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + nums[i - 1];
        }

        vector<vector<double>> dp(n + 1, vector<double> (K + 1));

        for (int i = 1; i <= n; i++) {
            dp[i][1] = sum[i] / i;
        }

        for (int i = 1; i <= n; i++) {
            for (int k = 2; k <= K; k++) {
                for (int j = 1; j < i; j++) {
                    double avg = (sum[i] - sum[j]) / (i - j);
                    dp[i][k] = max(dp[i][k], dp[j][k - 1] + avg);
                }
            }
        }

        return dp[n][K];
    }
};
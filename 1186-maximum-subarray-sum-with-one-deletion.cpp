// https://leetcode.cn/problems/maximum-subarray-sum-with-one-deletion/

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        vector<vector<int>> dp(arr.size(), vector<int>(2, 0));

        int res = arr[0];
        
        dp[0][0] = arr[0];
        dp[0][1] = arr[0];

        for(int i = 1; i < dp.size(); i++)
        {
            dp[i][0] = max(dp[i - 1][0] + arr[i], arr[i]);
            dp[i][1] = max(dp[i - 1][1] + arr[i], dp[i - 1][0]);

            res = max({res, dp[i][0], dp[i][1]});
        }

        return res;
    }
};
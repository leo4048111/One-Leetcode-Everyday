// https://leetcode.cn/problems/pizza-with-3n-slices/description/

class Solution {
public:
    int calculate(vector<int>& slices) {
        int N = slices.size();
        int n = (N + 1) / 3;
        vector<vector<int>> dp(N, vector<int>(n + 1, INT_MIN));

        dp[0][0] = 0;
        dp[0][1] = slices[0];
        dp[1][0] = 0;
        dp[1][1] = max(slices[0], slices[1]);

        for(int i = 2; i < N; i++) {
            dp[i][0] = 0;
            for(int j = 1; j <= n; j++) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 2][j - 1] + slices[i]);
            }
        }

        return dp[N - 1][n];
    }

    int maxSizeSlices(vector<int>& slices) {
        vector<int> tmp;

        for(int i = 1; i < slices.size(); i++) {
            tmp.push_back(slices[i]);
        }

        int ans = calculate(tmp);

        tmp.clear();

        for(int i = 0; i < slices.size() - 1; i++) {
            tmp.push_back(slices[i]);
        }

        ans = max(ans, calculate(tmp));

        return ans;
    }
};
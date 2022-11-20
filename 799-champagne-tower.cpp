// https://leetcode.cn/problems/champagne-tower/

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double dp[101][101];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = poured;

        for(int i = 0; i <= query_row; i++)
        {
            for(int j = 0; j <= i; j++)
            {
                if(dp[i][j] > 1.f) {
                    double of = dp[i][j] - 1.f;
                    dp[i][j] = 1.f;
                    dp[i + 1][j] += of / 2;
                    dp[i + 1][j + 1] += of / 2;
                }
            }
        }

        return dp[query_row][query_glass];
    }
};
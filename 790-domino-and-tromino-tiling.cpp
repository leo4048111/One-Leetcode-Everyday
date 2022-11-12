// https://leetcode.cn/problems/domino-and-tromino-tiling/

class Solution {
public:
    int numTilings(int N) {
        if(N < 2) return N;
        long long dp1[N + 1];
        long long dp2[N + 1];
        dp1[1] = 1;dp1[2] = 2;
        dp2[2] = 2;
        for(int i = 3; i <= N; i++)
        {
            dp1[i] = (dp1[i - 1] + dp1[i - 2] + dp2[i - 1]) % 1000000007;
            dp2[i] = (dp1[i - 2] * 2 + dp2[i - 1]) % 1000000007;
        }
            
        return dp1[N] % 1000000007;
    }
};
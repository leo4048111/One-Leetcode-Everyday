// https://leetcode.cn/problems/distinct-subsequences-ii/

class Solution {
public:
    int distinctSubseqII(string s) {
        const int mod = 1e9 + 7;
        int duplicationCnt[26];
        memset(duplicationCnt, 0, sizeof(duplicationCnt));
        unsigned int ans = 1;
        for(auto& c : s)
        {
            unsigned int newStrCnt = ans;
            ans = (ans % mod + newStrCnt % mod - duplicationCnt[c - 'a'] % mod + mod) % mod;
            duplicationCnt[c - 'a'] = newStrCnt;
        }

        return ans - 1;
    }
};
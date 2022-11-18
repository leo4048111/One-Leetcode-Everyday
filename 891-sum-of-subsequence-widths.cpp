// https://leetcode.cn/problems/sum-of-subsequence-widths/

class Solution {
    const int MOD = 1e9 + 7;
public:
    int sumSubseqWidths(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        // 先提前算好 2^i = pow2[i]
        vector<int> pow2(n); 
        pow2[0] = 1;
        for (int i = 1; i < n; i++) {
            pow2[i] = pow2[i - 1] * 2 % MOD;
        }
        
        int res = 0;
        for (int i = 0; i < n; i++) {
            int cnt = (pow2[i] - pow2[n - 1 - i]) * 1ll * nums[i] % MOD;
            res = (res + cnt) % MOD;
        }
        
        return res;
    }
};
// https://leetcode.cn/problems/split-array-with-same-average/

class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        vector<int> dp(sum + 1);
        dp[0] = 1 << 0;
        for (int num : nums) {
            for (int i = sum; i >= num; i--) {
                if (dp[i - num] != 0) {
                    dp[i] |= (dp[i - num] << 1);
                }
            }
        }
        
        for (int i = 1; i <= n / 2; i++) {
            if (sum * i % n == 0 && (dp[sum * i / n] & (1 << i))) return true;
        }
        
        return false;
    }
};
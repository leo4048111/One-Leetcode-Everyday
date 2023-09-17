// https://leetcode.cn/problems/house-robber-ii/description/?envType=daily-question&envId=2023-09-17

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(), ans = INT_MIN;
        vector<int> dp(n, 0);

        if(nums.size() == 1) return nums[0];

        if(nums.size() == 2) return max(nums[0], nums[1]);

        // ignore first house
        vector<int> tmp(nums.begin() + 1, nums.end());

        dp[0] = tmp[0];
        dp[1] = max(tmp[0], tmp[1]);
        for(int i = 2; i < tmp.size(); i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + tmp[i]);
        }

        ans = max(ans, dp[n - 2]);

        // ignore nums[nums.size() - 1]

        tmp = vector<int>(nums.begin(), nums.end() - 1);

        dp[0] = tmp[0];
        dp[1] = max(tmp[0], tmp[1]);
        for(int i = 2; i < tmp.size(); i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + tmp[i]);
        }

        ans = max(ans, dp[n - 2]);

        return ans;
    }
};
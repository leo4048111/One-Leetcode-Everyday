// https://leetcode.cn/problems/minimum-operations-to-reduce-x-to-zero/

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), ans = INT_MIN;
        int left = 0, right = 0;
        int sum = 0;
        int target = accumulate(nums.begin(), nums.end(), 0) - x;
        if(target < 0) return -1;
        if(target == 0) return n; 
        while(right < n)
        {
            if(right < n)
                sum += nums[right++];
            while(sum > target && left < n) {
                sum -= nums[left++];
            }
            if(sum == target) ans = max(ans, right - left);
        }

        return ans == INT_MIN ? -1 : n - ans;
    }
};
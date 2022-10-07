// https://leetcode.cn/problems/maximum-ascending-subarray-sum/

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int last = INT_MIN;
        int ans = nums[0];
        int sum = 0;
        for(auto& n: nums)
        {
            if(n > last) sum += n;
            else sum = n;
            last = n;
            if(sum > ans) ans = sum;
        }

        return ans;
    }
};
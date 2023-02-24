// https://leetcode.cn/problems/make-array-zero-by-subtracting-equal-amounts/

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int sum = 0;

        for(auto& e : nums)
        {
            if(e > sum)
            {
                sum = e;
                ans++;
            }
        }

        return ans;
    }
};
// https://leetcode.cn/problems/sign-of-the-product-of-an-array/

class Solution {
public:
    int arraySign(vector<int>& nums) {
        if(nums[0] == 0) return 0;
        int ans = (nums[0] > 0) ? 1 : -1;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] == 0) return 0;
            ans = (nums[i] > 0) ? ans : -ans;
        }
        return ans;
    }
};
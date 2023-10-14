// https://leetcode.cn/problems/single-number/description/?envType=daily-question&envId=2023-10-14

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        for(int i = 1; i < n; i++)
        {
            nums[i] ^= nums[i - 1]; 
        }
        return nums[n-1];
    }
};
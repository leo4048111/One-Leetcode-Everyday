// https://leetcode.cn/problems/remove-element/description/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ans = nums.size();
        for(int i = 0; i < ans; i++)
        {
            if(nums[i] == val)
            {
                for(int j = i + 1; j < nums.size(); j++)
                {
                    nums[j - 1] = nums[j];
                }
                ans--;
                i--;
            }
        }

        return ans;
    }
};
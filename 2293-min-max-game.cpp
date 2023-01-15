// https://leetcode.cn/problems/min-max-game/

class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        for(int j = 1; j < nums.size(); j *= 2) {
            for(int i = 0; i < nums.size() / 2; i++) {
                if(i % 2) {
                    nums[i] = max(nums[2 * i], nums[2 * i + 1]);
                }
                else nums[i] = min(nums[2 * i], nums[2 * i + 1]);
            }
        }

        return nums[0];
    }
};
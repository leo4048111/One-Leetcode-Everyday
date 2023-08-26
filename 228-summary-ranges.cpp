// https://leetcode.cn/problems/summary-ranges/description/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(nums.empty()) return ans;
        int left = 0;
        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i] + 1 != nums[i + 1]) {
                if(left == i) {
                    ans.push_back(to_string(nums[i]));
                } else {
                    ans.push_back(to_string(nums[left]) + "->" + to_string(nums[i]));
                }
                left = i + 1;
            }
        }

        if(left == nums.size() - 1) ans.push_back(to_string(nums[left]));
        else ans.push_back(to_string(nums[left]) + "->" + to_string(nums[nums.size() - 1]));

        return ans;
    }
};
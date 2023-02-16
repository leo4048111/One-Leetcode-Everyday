// https://leetcode.cn/problems/maximum-number-of-pairs-in-array/

class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        map<int, int> m;

        for(auto& num : nums) {
            m[num]++;
        }

        vector<int> ans(2);
        for(auto& p: m)
        {
            ans[0] += p.second / 2;
            ans[1] += p.second % 2;
        }

        return ans;
    }
};
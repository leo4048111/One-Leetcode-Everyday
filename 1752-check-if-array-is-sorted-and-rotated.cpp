// https://leetcode.cn/problems/check-if-array-is-sorted-and-rotated/

class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int> tmp;
        for(auto num : nums) tmp.push_back(num);
        for(auto num : nums) tmp.push_back(num);

        sort(nums.begin(), nums.end());

        for(int i = 0; i < tmp.size(); i++)
        {
            if(tmp[i] == nums[0])
            {
                bool isFind = true;
                for(int j = 0; j < nums.size(); j++)
                {
                    if(j + i >= tmp.size()) return false;

                    if(tmp[j + i] != nums[j]) isFind = false;
                }
                if(isFind) return true;
            }

        }

        return false;
    }
};
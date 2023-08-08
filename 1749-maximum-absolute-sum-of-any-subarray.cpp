// https://leetcode.cn/problems/maximum-absolute-sum-of-any-subarray/description/

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int sum = 0, max = 0, min = 0;

        for(auto& num : nums)
        {
            sum += num;

            if(sum > max) {
                max = sum;
            }

            if(sum < min) {
                min = sum;
            }
        }

        return max - min;
    }
};
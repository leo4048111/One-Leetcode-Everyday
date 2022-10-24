// https://leetcode.cn/problems/partition-array-into-disjoint-intervals/

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int N = nums.size();
        int rightMin[N];
        rightMin[N-1] = nums[N-1];
        for(int i = N - 2; i >= 0; i--)
            rightMin[i] = min(nums[i], rightMin[i + 1]);
        int leftMax = INT_MIN;
        for(int i = 0; i < nums.size() - 1; i++)
        {
            leftMax = max(leftMax, nums[i]);
            if(leftMax <= rightMin[i + 1]) return i + 1;
        }

        return N;
    }
};
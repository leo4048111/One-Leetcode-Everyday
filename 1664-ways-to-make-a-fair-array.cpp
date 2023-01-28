// https://leetcode.cn/problems/ways-to-make-a-fair-array/

class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        vector<int> oddSum;
        vector<int> evenSum;

        int lastOddSum = 0;
        int lastEvenSum = 0;

        int ans = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            if(i % 2)
            {
                oddSum.push_back(lastOddSum);
                evenSum.push_back(lastEvenSum + nums[i]);
                lastEvenSum += nums[i];
            }
            else
            {
                oddSum.push_back(lastOddSum + nums[i]);
                evenSum.push_back(lastEvenSum);
                lastOddSum += nums[i];
            }
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(i % 2) {
                int newOddSum = oddSum[i] + (evenSum[nums.size() - 1] - evenSum[i]);
                int newEvenSum = evenSum[i] - nums[i] + (oddSum[nums.size() - 1] - oddSum[i]);
                if(newEvenSum == newOddSum) ans++;
            }
            else {
                int newOddSum = oddSum[i] - nums[i] + (evenSum[nums.size() - 1] - evenSum[i]);
                int newEvenSum = evenSum[i] + (oddSum[nums.size() - 1] - oddSum[i]);
                if(newEvenSum == newOddSum) ans++;
            }
        }

        return ans;
    }
};
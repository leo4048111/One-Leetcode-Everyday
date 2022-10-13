// https://leetcode.cn/problems/max-chunks-to-make-sorted/

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int curMax = INT_MIN;
        int sum = 0;
        int ans = 0;
        for(auto& num : arr)
        {
            if(num > curMax)
                curMax = num;

            int totalSumShouldBe = (1 + curMax + 1) * (curMax + 1) / 2;

            sum += num + 1;
            if(sum == totalSumShouldBe)
            {
                ans++;
                curMax = INT_MIN;
            }
        }

        return ans;
    }
};
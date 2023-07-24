// https://leetcode.cn/problems/maximum-sum-circular-subarray/

class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {
        int N = nums.size();
        int ans = INT_MIN;
        int sum = INT_MIN;
        int startIdx = -1;
        int idx = 0;
        for (;;)
        {
            int num = nums[idx % N];
            if (sum < 0)
            {
                startIdx = idx;
                sum = num;
                ans = max(ans, sum);
            }
            else if (idx % N == startIdx % N)
            {
                int x = startIdx++;
                while (x % N != startIdx % N)
                {
                    if (nums[startIdx % N] < 0)
                        break;
                    startIdx++;
                }
                sum = nums[++startIdx % N];
                idx = startIdx;
                ans = max(ans, sum);
            }
            else
            {
                sum += num;
                ans = max(ans, sum);
            }

            idx++;

            if (startIdx >= N)
                break;
        }

        return ans;
    }
};
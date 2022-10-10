// https://leetcode.cn/problems/minimum-swaps-to-make-sequences-increasing/

// dp solution
class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int N = nums1.size();
        int dp[N][2];
        memset(dp, 0x3f, sizeof(dp));
        dp[0][0] = 0;
        dp[0][1] = 1;
        for(int i = 1; i < N; i++)
        {                                                        //        前后两组一起交换或者都不交换
            if(nums1[i] > nums1[i - 1] && nums2[i] > nums2[i-1]) //  a  b   -->   c   b   or  a  b   
            {                                                    //  c  d         a   d       c  d
                dp[i][0] = dp[i-1][0];
                dp[i][1] = dp[i-1][1] + 1;
            }
                                                                 //             交换后面一组或者前面一组
            if(nums1[i] > nums2[i-1] && nums2[i] > nums1[i-1])   //   a  b  -->   a   d    or  c  b   
            {                                                    //   c  d        c   b        a  d
                dp[i][0] = min(dp[i-1][1], dp[i][0]);
                dp[i][1] = min(dp[i-1][0] + 1, dp[i][1]);
            }
        }
        return min(dp[N - 1][0], dp[N - 1][1]);
    }
};
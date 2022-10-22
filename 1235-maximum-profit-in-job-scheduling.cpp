// https://leetcode.cn/problems/maximum-profit-in-job-scheduling/

class Solution {
public:
    static bool cmp(pair<int, int> e1, pair<int, int> e2) {
        return e1.first < e2.first;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int len = startTime.size();
        int p[len];
        int dp[len];
        memset(p, -1, sizeof(p));
        memset(dp, 0, sizeof(dp));
        vector<pair<int, int>> e(len);
        for(int i = 0; i < len; ++i) {
            e[i] = {endTime[i], i};
        }
        sort(e.begin(), e.end(), cmp);
        vector<int> startTime1(len);
        vector<int> profit1(len);
        for(int i = 0; i < len; ++i) {
            endTime[i] = e[i].first;
            startTime1[i] = startTime[e[i].second];
            profit1[i] = profit[e[i].second];
        }
        for(int i = 0; i < len; ++i) {
            if(startTime1[i] < endTime[0]) {
                continue;
            }
            auto it = upper_bound(endTime.begin(), endTime.end(), startTime1[i]);
            if(it != endTime.end())
                p[i] = it-endTime.begin()-1;
        }
        dp[0] = profit1[0];
        for(int i = 1; i < len; ++i) {
            if(p[i] == -1) dp[i] = max(profit1[i], dp[i-1]);
            else dp[i] = max(dp[p[i]]+profit1[i], dp[i-1]);
        }
        return dp[len-1];
    }
};

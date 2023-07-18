// https://leetcode.cn/problems/minimum-interval-to-include-each-query/

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int N = queries.size();

        vector<int> ans(N, -1);

        sort(intervals.begin(), intervals.end(), [](const vector<int>& v1, const vector<int>& v2) {
            return v1[1] - v1[0] < v2[1] - v2[0];
        });

        set<pair<int, int>> s;

        for(int i = 0; i < N; i++)
        {
            s.emplace(queries[i], i);
        }

        for(auto& interval : intervals)
        {
            auto iter = s.lower_bound({interval[0], -1});

            while((iter != s.end()) && iter->first <= interval[1]) {
                ans[iter->second] = interval[1] - interval[0] + 1;
                s.erase(iter++);
            }
        }

        return ans;
    }
};
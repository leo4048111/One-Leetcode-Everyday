// https://leetcode.cn/problems/merge-intervals/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), [&](vector<int>& v1, vector<int>& v2) {
            return v1[0] < v2[0];
        });

        if(intervals.size() <= 1) return intervals;

        for(int i = 0; i < intervals.size(); i++) {
            auto& v1 = intervals[i];
            int j = i + 1;
            int left = v1[0], right = v1[1];
            while(j < intervals.size() && right >= intervals[j][0]) {
                right = max(right, intervals[j][1]);
                j++;
            }
            ans.push_back({left, right});
            i = j - 1;
        }

        return ans;
    }
};
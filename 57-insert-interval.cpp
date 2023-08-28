// https://leetcode.cn/problems/insert-interval/description/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        intervals.push_back(newInterval);

        sort(intervals.begin(), intervals.end(), [&](vector<int>& v1, vector<int>& v2) {
            return v1[0] < v2[0];
        });

        for(int i = 0; i < intervals.size(); i++) {
            int left = intervals[i][0];
            int right = intervals[i][1];
            int j = i + 1;
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
// https://leetcode.cn/problems/earliest-possible-day-of-full-bloom/description/?envType=daily-question&envId=2023-09-30

class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<tuple<int, int>> seeds;
        int n = plantTime.size();
        for(int i = 0; i < n; i++) {
            seeds.push_back({plantTime[i], growTime[i]});
        }

        sort(seeds.begin(), seeds.end(), [&](tuple<int, int>& l, tuple<int, int>& r){
            return get<1>(l) > get<1>(r);
        });

        int curTime = 0, ans = 0;
        for(auto& [pt, gt] : seeds) {
            curTime += pt;
            ans = max(ans, curTime + gt);
        }

        return ans;
    }
};
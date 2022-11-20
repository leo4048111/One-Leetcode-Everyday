// https://leetcode.cn/problems/find-the-highest-altitude/

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum = 0;
        int ans = 0;
        for(auto& n : gain) {
            sum += n;
            ans = max(sum, ans);
        }

        return ans;
    }
};
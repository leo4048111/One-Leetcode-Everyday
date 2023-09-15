// https://leetcode.cn/problems/WHnhjV/description/?envType=daily-question&envId=2023-09-15

class Solution {
public:
    int giveGem(vector<int>& gem, vector<vector<int>>& operations) {
        for(auto& op : operations) {
            gem[op[1]] += gem[op[0]] / 2;
            gem[op[0]] = gem[op[0]] - gem[op[0]] / 2;
        }

        int minVal = INT_MAX;
        int maxVal = INT_MIN;
        for(auto& g : gem) {
            minVal = min(g, minVal);
            maxVal = max(g, maxVal);
        }

        return maxVal - minVal;
    }
};
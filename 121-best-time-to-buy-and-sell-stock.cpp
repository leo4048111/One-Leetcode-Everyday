// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/discussion/?envType=daily-question&envId=2023-10-01

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxVal = 0, buyAt = INT_MAX;

        for(auto& price : prices) {
            if(price < buyAt) buyAt = price;
            else maxVal = max(maxVal, price - buyAt);
        }

        return maxVal;
    }
};
// https://leetcode.cn/problems/maximum-number-of-consecutive-values-you-can-make/

class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        int sum = 0;
        sort(coins.begin(), coins.end());
        for(auto& coin : coins)
        {
            if(coin <= sum + 1) {
                sum += coin;
            }
            else break;
        }

        return sum + 1;
    }
};
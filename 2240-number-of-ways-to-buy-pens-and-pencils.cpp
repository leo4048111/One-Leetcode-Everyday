// https://leetcode.cn/problems/number-of-ways-to-buy-pens-and-pencils/?envType=daily-question&envId=2023-09-01

class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        using ll = long long;
        ll ans = 0;

        for(int i = 0; i <= total / cost1; i++) {
            ans += (total - (cost1 * i)) / cost2 + 1; 
        }        

        return ans;
    }
};
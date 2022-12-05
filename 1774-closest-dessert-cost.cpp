// https://leetcode.cn/problems/closest-dessert-cost/

class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        bitset<20005> f;
        for(auto x:baseCosts)f[x]=1;
        for(auto x:toppingCosts)f|=(f<<x)|(f<<(x*2));
        int ans=-20000;
        for(int x=0;x<=20000;++x)
            if(f[x] && abs(x-target)<abs(ans-target))
                ans=x;
        return ans;
    }
};
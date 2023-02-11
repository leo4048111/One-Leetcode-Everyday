// https://leetcode.cn/problems/minimum-amount-of-time-to-fill-cups/

class Solution {
public:
    int fillCups(vector<int>& amount) {
        int ans = 0;
        while(amount[0] || amount[1] || amount[2])
        {
            sort(amount.begin(), amount.end());
            if(amount[0]) {
                amount[0]--;
            }
            else if(amount[1]) {
                amount[1]--;
            }
            
            amount[2]--;
            ans++;
        }

        return ans;
    }
};
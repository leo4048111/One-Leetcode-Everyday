// https://leetcode.cn/problems/find-the-losers-of-the-circular-game/description/

class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        map<int, int> count;
        vector<int> ans;
        int i = 1;
        int cur = 1;
        for(;;) {
            count[cur]++;
            if(count[cur] == 2) break;

            cur += i * k;
            while(cur > n) cur -= n;
            i++;
        }

        for(int i = 1; i <= n; i++) {
            if(count[i] == 0) ans.push_back(i);
        }

        return ans;
    }
}; 
// https://leetcode.cn/problems/maximize-distance-to-closest-person/description/

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int N = seats.size();
        int cnt = 0;
        int M = INT_MIN;
        for(int i = 0; i < N; i++) {
            if(seats[i]) {
                M = max(cnt, M); 
                cnt = 0;
            }
            else cnt++;
        }

        int ans = M / 2 + M % 2;

        if(!seats[0]) {
            int cnt = 0;
            while(cnt < N && !seats[cnt]) cnt++;
            ans = max(ans, cnt);
        }

        if(!seats[N - 1]) {
            int cnt = N - 1;
            while(cnt >= 0 && !seats[cnt]) cnt--;

            ans = max(N - cnt - 1, ans);
        }

        return ans;
    }
};
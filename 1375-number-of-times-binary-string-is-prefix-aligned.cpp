class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int N = flips.size();
        int x = 0;

        int ans = 0;

        for(int i = 1; i <= N; i++)
        {
            x = max(flips[i - 1], x);

            if(x == i) ans++;
        }

        return ans;
    }
};
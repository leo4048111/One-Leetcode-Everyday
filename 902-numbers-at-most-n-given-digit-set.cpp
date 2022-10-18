// https://leetcode.cn/problems/numbers-at-most-n-given-digit-set/

// pasted solution
const int N = 15;
class Solution {
    
    int f[N][N];
    int nums[N], idx = 0;
    unordered_set<int> st;

    int dp(int pos, int last, int op) {
        if (!pos) {return 1;}
        if (!op && f[pos][last] != -1) return f[pos][last];
        int ans = 0;
        int up = op ? nums[pos] : 9;
        for (int i = 0; i <= up; ++i) {
            if (st.count(i) || (i == 0 && last == 0)) {
                ans += dp(pos - 1, i, op && i == up);
            }
        }
        if (!op) f[pos][last] = ans;
        return ans;
    }

    int calc(int n)
    {
        while (n) nums[++idx] = n % 10, n /= 10;
        memset(f, -1, sizeof f);
        return dp(idx, 0, 1);
    }

public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        for (string x : digits) st.insert(stoi(x));
        int cnt = 0;
        if (n > 99) for (int x : st) if (x <= n) cnt++;
        return calc(n) - 1;  // -1 是因为把全为0得去掉
    }
};
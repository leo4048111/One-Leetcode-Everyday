// https://leetcode.cn/problems/nth-magical-number/

class Solution {
    typedef long long LL;
    const int MOD = 1e9 + 7;
public:
    int nthMagicalNumber(int n, int a, int b) {
        int lcm = a / gcd(a, b) * b;

        LL l = 0;
        LL r =  n * 1ll * min(a, b);
        while (l < r) {
            LL mid = (l + r) >> 1;
            LL cnt = mid / a + mid / b - mid / lcm;
            if (cnt >= n) {
                r = mid; 
            } else {
                l = mid + 1; 
            }
        }

        return l % MOD;
    }

};
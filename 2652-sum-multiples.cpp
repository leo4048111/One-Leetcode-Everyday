// https://leetcode.cn/problems/sum-multiples/description/?envType=daily-question&envId=2023-10-17

class Solution {
public:
    int sumOfMultiples(int n) {
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            if(!(i % 3) || !(i % 5) || !(i % 7)) {
                ans += i;
            }
        }

        return ans;
    }
};
// https://leetcode.cn/problems/pass-the-pillow/description/?envType=daily-question&envId=2023-09-26

class Solution {
public:
    int passThePillow(int n, int time) {
        time %= (2 * (n - 1));

        return time >= n ? 2 * n - time - 1 : 1 + time;
    }
};
// https://leetcode.cn/problems/minimum-number-of-operations-to-reinitialize-a-permutation/

class Solution {
public:
    int reinitializePermutation(int n) {
        int pos = 1;
        int ans = 0;

        do
        {
            pos = (pos % 2 == 0) ?  pos / 2 : n / 2 + (pos - 1) / 2;
            ans++;
        }while(pos != 1);

        return ans;
    }
};
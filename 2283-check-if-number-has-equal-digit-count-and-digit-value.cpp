// https://leetcode.cn/problems/check-if-number-has-equal-digit-count-and-digit-value/

class Solution {
public:
    bool digitCount(string num) {
        int cnt[99];
        memset(cnt, 0, sizeof(cnt));
        for(auto digit : num) {
            cnt[digit - '0']++;
        }

        for(int i = 0; i < num.size(); i++) {
            if((num[i] - '0') != cnt[i]) return false;
        }

        return true;
    }
};
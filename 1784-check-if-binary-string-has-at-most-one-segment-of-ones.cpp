// https://leetcode.cn/problems/check-if-binary-string-has-at-most-one-segment-of-ones/

class Solution {
public:
    bool checkOnesSegment(string s) {
        bool isLast0 = true;
        int cnt = 0;
        for(auto& c : s)
        {
            if(isLast0 && c == '1') cnt++;
            if(cnt >= 2) return false;
            isLast0 = c == '0';
        }

        return true;
    }
};
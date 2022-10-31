// https://leetcode.cn/problems/magical-string/

class Solution {
public:
    int magicalString(int n) {
        string s = "\1\2\2"; 
        for (int i = 2; s.length() < n; ++i)
            s += string(s[i], s.back() ^ 3);
        return count(s.begin(), s.begin() + n, 1);
    }
};

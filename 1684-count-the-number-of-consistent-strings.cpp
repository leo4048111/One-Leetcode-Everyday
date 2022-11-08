// https://leetcode.cn/problems/count-the-number-of-consistent-strings/

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int mask = 0;
        for (char &c : allowed) {
            mask |= 1 << (c - 'a');
        }
        return count_if(words.begin(), words.end(), [&](string &s) -> bool {
            for (char &c : s) {
                if ((mask >> (c - 'a') & 1) == 0) return false;
            } 
            return true;
        });
    }
};
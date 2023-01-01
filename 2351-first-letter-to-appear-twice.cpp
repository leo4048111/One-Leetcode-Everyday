// https://leetcode.cn/problems/first-letter-to-appear-twice/

class Solution {
public:
    char repeatedCharacter(string s) {
        int count[26];
        memset(count, 0, sizeof(count));
        for(auto c : s) {
            count[c - 'a']++;
            if(count[c - 'a'] == 2) {
                return c;
            }
        }
        return 0;
    }
};
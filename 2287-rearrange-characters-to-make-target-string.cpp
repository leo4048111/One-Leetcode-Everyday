// https://leetcode.cn/problems/rearrange-characters-to-make-target-string/

class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int cnt[26];
        memset(cnt, 0, sizeof(cnt));
        int cnt2[26];
        memset(cnt2, 0, sizeof(cnt2));

        for(auto c : s) cnt[c - 'a']++;
    
        for(auto c : target) cnt2[c - 'a']++;

        int ans = INT_MAX;

        for(auto c : target) ans = min(ans, cnt[c - 'a'] / cnt2[c - 'a']);

        return ans;
    }
};
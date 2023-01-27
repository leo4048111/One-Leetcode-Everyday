// https://leetcode.cn/problems/greatest-english-letter-in-upper-and-lower-case/

class Solution {
public:
    string greatestLetter(string s) {
        bool cnt[52];
        memset(cnt, 0, sizeof(cnt));
        string ans = "";
        for(auto& c :s) {
            if(c >= 'a' && c <= 'z') {
                cnt[c - 'a'] = true;
            }
            else
                cnt[c - 'A' + 26] = true;
        }

        for(int i = 25; i >= 0; i--)
        {
            if(cnt[i] && cnt[i + 26]) {
                ans += (char)(i + 'A');
                return ans;
            }
        }

        return ans;
    }
};
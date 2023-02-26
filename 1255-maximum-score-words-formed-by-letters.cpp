// https://leetcode.cn/problems/maximum-score-words-formed-by-letters/

class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int cnt[26] = {0};
        for (char & c : letters) ++cnt[c-'a'];
        int n = words.size(), ans = 0;

        int a[26];
        auto check = [&](int id) -> bool {
            for (char & c : words[id]) {
                ++a[c-'a'];
                if (a[c-'a'] > cnt[c-'a'])return false;
            }
            return true;
        };

        for (int kind = 1; kind < (1<<n); ++kind) {
            memset(a, 0, sizeof (a));
            bool isok = 1;
            for (int i = 0; i < n; ++i)
                if (kind & 1<<i)if (!check(i)) {isok = 0;break;}
            if (!isok) continue;
            int sum = 0;
            for (int i = 0; i < 26; ++i)sum += a[i]*score[i];
            ans = max(ans, sum);
        }

        return ans;
    }
};
// https://leetcode.cn/problems/determine-if-string-halves-are-alike/

class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size();
        unordered_set<char> st = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int cnt = 0;
        for (int i = 0; i < n / 2; i++) {
            cnt += st.count(s[i]); 
            cnt -= st.count(s[i + n / 2]);
        }
        return cnt == 0; 
    }
};
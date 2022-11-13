// https://leetcode.cn/problems/custom-sort-string/

map<char, int> m;

bool cmp(char a, char b) {
    return m[a] < m[b];
}

class Solution {
public:
    string customSortString(string order, string s) {
        int idx = 0;
        for (auto c : order) {
            m[c] = idx++;
        }
        sort(s.begin(), s.end(), cmp);
        return s;
    }
};
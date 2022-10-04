// https://leetcode.cn/problems/minimum-add-to-make-parentheses-valid/

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        if(!s.size()) return 0;
        st.push(s[0]);
        for(int i = 1; i < s.size();i++)
        {
            char c = s[i];
            if(st.empty()) st.push(c);
            else if(st.top() == '(' && c == ')') st.pop();
            else st.push(c);
        }

        return st.size();
    }
};
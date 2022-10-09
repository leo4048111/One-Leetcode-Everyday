// https://leetcode.cn/problems/score-of-parentheses/

class Solution {
public:
    int scoreOfParentheses(string s) {
        char lastChar = s[0];
        int mod = 1;
        int ans = 0;
        for(int i =1;i < s.size();i++)
        {
            char c = s[i];
            if(lastChar == '(' && c == '(') mod *= 2;
            else if(lastChar == '(' && c == ')') ans += mod;
            else if(lastChar == ')' && c == ')') mod /= 2;

            lastChar = c;
        }

        return ans;
    }
};
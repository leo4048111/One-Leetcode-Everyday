// https://leetcode.cn/problems/strong-password-checker-ii/

class Solution
{
public:
    bool strongPasswordCheckerII(string pwd)
    {
        if (pwd.size() < 8)
            return 0;
        char t = 0, a = 0, A = 0, num = 0, u = 0;
        for (auto &c : pwd)
        {
            if (t == c)
                return 0;
            t = c;
            if (c >= '0' && c <= '9')
                num = 1;
            else if (c >= 'a' && c <= 'z')
                a = 1;
            else if (c >= 'A' && c <= 'Z')
                A = 1;
            else if (c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '^' || c == '&' || c == '*' || c == '(' || c == ')' || c == '-' || c == '+')
                u = 1;
        }

        return a + A + num + u == 4;
    }
};
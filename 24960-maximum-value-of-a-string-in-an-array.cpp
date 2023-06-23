// https://leetcode.cn/problems/maximum-value-of-a-string-in-an-array/

class Solution
{
public:
    int getVal(string &s)
    {
        int val = 0;
        for (auto &c : s)
        {
            if (c > '9' || c < '0')
                return s.size();
            val = val * 10 + c - '0';
        }

        return val;
    }
    int maximumValue(vector<string> &strs)
    {
        int ans = INT_MIN;
        for (auto &s : strs)
        {
            ans = max(ans, getVal(s));
        }

        return ans;
    }
};
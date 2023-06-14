// https://leetcode.cn/problems/ba-zi-fu-chuan-zhuan-huan-cheng-zheng-shu-lcof/

class Solution {
public:
    int strToInt(string str) {
        int i = 0;
        while(str[i] == ' ') i++;

        long long ans = 0;
        bool shouldNegate = false;
        if(str.size() && str[i] == '-') shouldNegate = true;

        bool isFirst = true;
        for(i; i < str.size(); i++)
        {
            char c = str[i];
            if((c == '-' || c == '+') && isFirst)
            {
                isFirst = false;
                continue;
            }
            if(!isdigit(c)) break;

            isFirst = false;

            ans = ans * 10 + (c - '0');
            if(shouldNegate && (-ans < INT_MIN)) return INT_MIN;

            if(!shouldNegate && (ans > INT_MAX)) return INT_MAX;
        }

        if(shouldNegate) ans = -ans;

        return ans;
    }
};
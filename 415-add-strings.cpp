// https://leetcode.cn/problems/add-strings/

class Solution {
public:
    string addStrings(string num1, string num2) {
        string res;

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        int i = 0;
        int carry = 0;
        for(;i < min(num1.size(), num2.size()); i++)
        {
            int tmp = (num1[i] - '0') + (num2[i] - '0') + carry;
            carry = tmp / 10;
            res += (tmp % 10) + '0';
        }

        while(i < num1.size())
        {
            int tmp = num1[i] - '0' + carry;
            carry = tmp / 10;
            res += (tmp % 10) + '0';
            i++;
        }

        while(i < num2.size())
        {
            int tmp = num2[i] - '0' + carry;
            carry = tmp / 10;
            res += (tmp % 10) + '0';
            i++;
        }

        if(carry > 0) res += carry + '0';
        reverse(res.begin(), res.end());

        return res;
    }
};
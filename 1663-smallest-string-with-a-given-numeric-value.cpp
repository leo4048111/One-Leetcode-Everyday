// https://leetcode.cn/problems/smallest-string-with-a-given-numeric-value/

class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans;
        for(int i = 0; i < n; i++)
        {
            ans += 'a';
            k--;
        }

        int pos = ans.size() - 1;
        while(k)
        {
            if(ans[pos] < 'z')
            {
                ans[pos]++;
                k--;
            }
            else
                pos--;
        }

        return ans;
    }
};
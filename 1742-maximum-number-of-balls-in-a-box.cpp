// https://leetcode.cn/problems/maximum-number-of-balls-in-a-box/

class Solution {
public:
    int countBalls(int l, int h) {
        vector<int> sum(50,0);
        int res=-1;
        for(int i=l;i<=h;++i)
        {
            int x=i,s=0;
            while(x)s+=x%10,x/=10;
            sum[s]++;
            res=max(res,sum[s]);
        }
        return res;
    }
};
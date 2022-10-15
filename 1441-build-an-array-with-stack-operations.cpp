// https://leetcode.cn/problems/build-an-array-with-stack-operations/

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int lastNum = 0;
        vector<string> ans;
        for(auto& num : target)
        {
            if(num != lastNum + 1)
            {
                for(int i = lastNum + 1; i < num; i++)
                {
                    ans.push_back("Push");
                    ans.push_back("Pop");
                }
            }
            lastNum = num;
            ans.push_back("Push");
        }

        return ans;
    }
};
// https://leetcode.cn/problems/letter-case-permutation/

class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        int dis = 'A'-'a';
        function<void(int, string)> dfs = [&](int start, string baseStr) {
            ans.push_back(baseStr);
            for(int i = start; i < baseStr.size(); i++)
            {
                char c = baseStr[i];
                if(c >= 'a' && c <= 'z')
                {
                    baseStr[i] += dis;
                    dfs(i+1, baseStr);
                    baseStr[i] -= dis;
                } 
                else if(c >= 'A' && c <= 'Z')
                {
                    baseStr[i] -= dis;
                    dfs(i+1, baseStr);
                    baseStr[i] += dis;
                }
            }
        };

        dfs(0, s);
        return ans;
    }
};
// https://leetcode.cn/problems/ti-huan-kong-ge-lcof/?envType=study-plan-v2&envId=coding-interviews

class Solution {
public:
    string replaceSpace(string s) {
        string tmp;

        for(auto& c : s)
        {
            if(c == ' ') {
                tmp += "%20";
            }else tmp +=c;
        }

        return tmp;
    }
};
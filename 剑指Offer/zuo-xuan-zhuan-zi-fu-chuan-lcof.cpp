// https://leetcode.cn/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/?envType=study-plan-v2&envId=coding-interviews

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string x = s.substr(0, n);
        string y = s.substr(n, s.size() - n);

        return y + x;
    }
};
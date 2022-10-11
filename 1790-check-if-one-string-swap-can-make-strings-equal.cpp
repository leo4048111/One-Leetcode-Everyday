// https://leetcode.cn/problems/check-if-one-string-swap-can-make-strings-equal/

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1 == s2) return true;

        vector<int> toSwap;

        for(int i = 0; i < s1.size(); i++)
        {
            if(s1[i] != s2[i]) toSwap.push_back(i);
        }
        
        if(toSwap.size() > 2 || toSwap.size() == 1) return false;
        swap(s1[toSwap[0]], s1[toSwap[1]]);
        return s1 == s2;
    }
};
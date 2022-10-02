// https://leetcode.cn/problems/reformat-phone-number/

class Solution {
public:
    string reformatNumber(string number) {
        string s;
        for(char& c: number)
        {
            if(c != '-' && c != ' ') s += c;
        }
        
        string s2;
        int mod = (s.size() % 3 == 1) ? 4 : (s.size() % 3);
        for(int i = 0; i < (s.size() - mod) /3; i++)
        {
            s2 += s.substr(i * 3, 3);
            s2 += '-';
        }

        for(int j = s.size() - mod; j < s.size(); j += 2)
        {
            s2 += s[j];
            s2 += s[j + 1];
            s2 += '-';
        }

        return s2.substr(0, s2.size() - 1);
    }
};
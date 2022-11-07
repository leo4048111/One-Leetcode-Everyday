// https://leetcode.cn/problems/ambiguous-coordinates/

class Solution {
public:
    vector<string> ambiguousCoordinates(string s) {
        int n = s.size();
        vector<string> res;
        
        for (int k = 1; k <= n - 3; k++) {
            string l = s.substr(1, k);
            string r = s.substr(k + 1, n - 2 - k);
            vector<string> left = f(l);
            vector<string> right = f(r);
            for (string &x : left) {
                for (string &y : right) {
                    res.push_back("(" + x + ", " + y + ")");
                }
            }
        }
        return res;
    }
    
private:
    vector<string> f(string &s) {
        int n = s.size();
        
        if (n == 1) return {s};
        
        if (s[0] == '0' && s[n - 1] == '0') return {};
        
        if (s[n - 1] == '0') return {s};
        
        if (s[0] == '0') return {"0." + s.substr(1)};

        vector<string> res;
        res.push_back(s);
        for (int i = 1; i <= n - 1; i++) {
            string a = s.substr(0, i);
            string b = s.substr(i);
            res.push_back(a + "." + b); 
        }
        return res;
    }
};
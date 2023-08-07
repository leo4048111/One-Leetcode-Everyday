// https://leetcode.cn/problems/zigzag-conversion/description/

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        
        vector<string> v(numRows, "");

        int curRow = 0;
        int dir = 1;

        for(auto& c : s) {
            v[curRow] += c;

            curRow += dir;

            if(curRow == numRows) {
                dir = -1;
                curRow -= 2;
            }

            if(curRow == -1) {
                dir = 1;
                curRow += 2;
            }
        }

        string ans;
        for(auto& row : v) {
            ans += row;
        }

        return ans;
    }
};
// https://leetcode.cn/problems/minimum-changes-to-make-alternating-binary-string/

class Solution {
public:
    int minOperations(string s) {
        char x = '0';
        int cnt0 = 0, cnt1 = 0;
        for (char c : s) {
            if (c != x) {
                cnt0++; 
            } else {
                cnt1++;
            } 
            x ^= 1;
        }    
        return min(cnt0, cnt1); 
    }
};
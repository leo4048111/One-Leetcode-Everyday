// https://leetcode.cn/problems/reverse-string/description/

class Solution {
public:
    void reverseString(vector<char>& s) {
        int N = s.size();
        int left = 0, right = N - 1;

        while(left < right) {
            char tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            left++;
            right--;
        }
    }
};
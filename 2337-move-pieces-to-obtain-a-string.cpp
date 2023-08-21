// https://leetcode.cn/problems/move-pieces-to-obtain-a-string/description/

class Solution {
public:
    bool canChange(string start, string target) {
        int i = 0, j = 0;
        int n = start.size();

        while(true) {
            while(i < n && start[i] == '_') i++;

            while(j < n && target[j] == '_') j++;

            if(i >= n && j >= n) return true;

            if(start[i] != target[j]) return false;

            if(start[i] == 'R' && i > j) return false;

            if(start[i] == 'L' && i < j) return false;

            i++, j++;
        }
    }
};
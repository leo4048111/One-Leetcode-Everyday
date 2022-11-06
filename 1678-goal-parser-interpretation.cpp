// https://leetcode.cn/problems/goal-parser-interpretation/

class Solution {
public:
    string interpret(string command) {
        int n = command.size();
        string res;
        for (int i = 0; i < n; i++) {
            if (command[i] == 'G') {
                res += "G"; 
            } else if (command[i] == '(' && command[i + 1] == ')') {
                res += "o"; 
                i++;
            } else { // "(al)"
                res += "al"; 
                i += 3;
            }
        }      
        return res;
    }
};
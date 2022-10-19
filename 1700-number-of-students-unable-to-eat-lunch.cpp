// https://leetcode.cn/problems/number-of-students-unable-to-eat-lunch/

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int need[2];
        memset(need, 0, sizeof(need));
        for(auto like : students) need[like]++;
        for(auto have : sandwiches) 
        {
            if(need[have] > 0) need[have]--;
            else break;
        }

        return need[0] + need[1];
    }
};
// https://leetcode.cn/problems/course-schedule-ii/description/?envType=daily-question&envId=2023-09-10

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;

        map<int, int> count;
        int cnt = 0;
        vector<vector<int>> prereq = vector<vector<int>>(numCourses, vector<int>());

        for(auto& p : prerequisites) {
            prereq[p[1]].push_back(p[0]);
            count[p[0]]++;
        }

        queue<int> q;

        for(int i = 0; i < numCourses; i++) {
            if(!count[i]) q.push(i);
        }

        while(q.size()) {
            auto tmp = q.front();
            q.pop();
            ans.push_back(tmp);
            cnt++;
            for(auto& course : prereq[tmp]) {
                count[course]--;
                if(!count[course]) q.push(course);
            }
        }

        return cnt == numCourses ? ans : vector<int>();
    }
};
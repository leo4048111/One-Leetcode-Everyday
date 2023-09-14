// https://leetcode.cn/problems/course-schedule-iv/?envType=daily-question&envId=2023-09-12

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>> &prerequisites, vector<vector<int>> &queries) {
        vector<int> e[numCourses];
        for (auto &pi: prerequisites)
            e[pi[1]].push_back(pi[0]);
        vector<int> vis(numCourses, -1);
        int is[numCourses][numCourses];
        memset(is, 0, sizeof(is));
        for (int i = 0; i < numCourses; i++) {
            queue<int> q;
            q.push(i);
            vis[i] = i;
            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                for (auto j: e[cur])
                    if (vis[j] != i) {
                        vis[j] = i;
                        is[j][i] = 1;
                        q.push(j);
                    }
            }
        }
        vector<bool> res;
        for (auto &qi: queries)
            res.push_back(is[qi[0]][qi[1]]);
        return res;
    }
};
// https://leetcode.cn/problems/course-schedule/?envType=daily-question&envId=2023-09-09

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> deps(numCourses, vector<int>());
        map<int, int> cnt;
        for(auto& p : prerequisites) {
            deps[p[1]].push_back(p[0]);
            cnt[p[0]]++;
        }
        
        int count = 0;
        queue<int> canLearn;
        for(int i = 0; i < numCourses; i++) {
            if(!cnt[i]) canLearn.push(i);
        }

        while(canLearn.size()) {
            int classNo = canLearn.front();
            canLearn.pop();
            count++;
            for(auto& classNo2 : deps[classNo]) {
                cnt[classNo2]--;
                if(!cnt[classNo2]) canLearn.push(classNo2);
            }
        }

        return count == numCourses;
    }
};
// https://leetcode.cn/problems/course-schedule-iii/discussion/?envType=daily-question&envId=2023-09-11

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [&](vector<int> v1, vector<int> v2) {
            return v1[1] < v2[1];
        });

        int total = 0;
        priority_queue<int> q;
        for(auto& c : courses) {
            int dur = c[0], lastDay = c[1];
            if(total + dur <= lastDay) {
                total += dur;
                q.push(dur);
            }
            else if(q.size() && q.top() > dur) {
                total = total - q.top() + dur;
                q.pop();
                q.push(dur);
            }
        }

        return q.size();
    }
};
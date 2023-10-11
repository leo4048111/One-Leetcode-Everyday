// https://leetcode.cn/problems/reward-top-k-students/description/?envType=daily-question&envId=2023-10-11

class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        map<string, int> score;
        map<int, int> studentScores;

        for(auto&x : positive_feedback) score[x] = 3;
        for(auto&x : negative_feedback) score[x] = -1;

        vector<int> ans;
        int n = report.size();
        for(int i = 0; i < n; i++) {
            string sentence = report[i];
            int curscore = 0;
            int left = 0, right = 0;

            while(left < sentence.size() && right < sentence.size()) {
                while(right < sentence.size() && sentence[right] != ' ') right++;
                
                if(right != left) {
                    string word = sentence.substr(left, right - left);
                    curscore += score[word];
                }

                left = right + 1;
                right = left;
            }

            studentScores[student_id[i]] = curscore;
        }

        sort(student_id.begin(), student_id.end(), [&](int l, int r) {
            if(studentScores[l] == studentScores[r]) return l < r;

            return studentScores[l] > studentScores[r];
        });

        for(int i = 0; i < k; i++) {
            ans.push_back(student_id[i]);
        }

        return ans;
    }
};
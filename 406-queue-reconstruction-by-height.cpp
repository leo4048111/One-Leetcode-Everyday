// https://leetcode.cn/problems/queue-reconstruction-by-height/description/

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> ans;

        sort(people.begin(), people.end(), [](const vector<int> &p1, const vector<int> &p2) {
            if(p1[0] != p2[0]) return p1[0] > p2[0];
            
            return p1[1] < p2[1];
        });

        for(auto& p : people) {
            if(ans.size() <= p[1]) {
                ans.push_back(p);
            }
            else {
                ans.insert(ans.begin() + p[1], p);
            }
        }

        return ans;
    }
};
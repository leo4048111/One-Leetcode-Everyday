// https://leetcode.cn/problems/finding-the-users-active-minutes/

class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        sort(logs.begin(), logs.end(), [&](vector<int>& a, vector<int>& b){
            if(a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        });
        unordered_map<int, int> data;
        data[logs[0][0]]++;
        for(int i = 1; i < logs.size(); i++){
            if(logs[i] != logs[i - 1]){
                data[logs[i][0]]++;
            }
        }
        vector<int> res(k, 0);
        for(auto d : data){
            res[d.second - 1]++;
        }
        return res;
    }
};
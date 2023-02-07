// https://leetcode.cn/problems/alert-using-same-key-card-three-or-more-times-in-a-one-hour-period/

class Solution {
public:
    int convert(string time){
        int res = 0;
        int minues = (time[0] - '0') * 10 + (time[1] - '0');
        int second = (time[3] - '0') * 10 + (time[4] - '0');
        return minues * 60 + second;
    }
    bool judge(vector<int>& ve){
        sort(ve.begin(), ve.end());
        for(int i = 2; i < ve.size(); i++){
            if(ve[i] - ve[i - 2] <= 60) return true;
        }
        return false;
    }
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        map<string, vector<int>> map;
        vector<string> res;
        for(int i = 0; i < keyName.size(); i++){
            string name = keyName[i];
            string time = keyTime[i];
            map[name].push_back(convert(time));
        }
        for(auto [k, v] : map){
            if(judge(v)){
                res.push_back(k);
            }
        }
        return res;
    }
};
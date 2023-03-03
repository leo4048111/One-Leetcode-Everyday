// https://leetcode.cn/problems/making-file-names-unique/

class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        vector<string> ans;
        map<string, int> m;
        for(auto name : names) {
            if(m.find(name) == m.end()) {
                m.insert(make_pair(name, 1));
                ans.push_back(name);
            }
            else {
                int cnt = m[name];

                while(true) {
                    string tmp = name + "(" + to_string(cnt++) + ")";

                    if(m.find(tmp) == m.end()) {
                        m[name] = cnt;
                        m.insert(make_pair(tmp, 1));
                        ans.push_back(tmp);
                        break;
                    }
                }
            }
        }

        return ans;
    }
};
// https://leetcode.cn/problems/group-anagrams/description/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string, vector<string>> m;

        for(auto& s : strs)
        {
            string origin = s;
            sort(s.begin(), s.end());
            if(m.find(s) == m.end()) {
                vector<string> tmp;
                tmp.push_back(origin);
                m[s] = tmp;
            } else {
                m[s].push_back(origin);
            }
        }

        for(auto& tmp : m) {
            ans.push_back(tmp.second);
        }

        return ans;
    }
};
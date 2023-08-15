// https://leetcode.cn/problems/find-and-replace-in-string/description/

class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        vector<string> arr;
        string ans;
        int k = indices.size();

        for(auto& c : s) {
            string ss;
            ss += c;
            arr.push_back(ss);
        }
        
        for(int i = 0; i < k; i++) {
            int idx = indices[i];
            string src = sources[i];
            string rep = targets[i];
            string tmp = s.substr(idx, src.size());
            if(tmp == src) {
                arr[idx] = rep;
                for(int j = idx + 1; j < idx + src.size(); j++) {
                    arr[j] = "";
                }
            }            
        }

        for(auto& x : arr) {
            ans += x;
        }

        return ans;
    }
};
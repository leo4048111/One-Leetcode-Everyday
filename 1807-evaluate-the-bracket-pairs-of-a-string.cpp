// https://leetcode.cn/problems/evaluate-the-bracket-pairs-of-a-string/

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        map<string, string> kn;

        for(auto pair : knowledge) {
            kn.insert(make_pair(pair[0], pair[1]));
        }

        bool inBracket = false;
        string key = "";
        string ans = "";
        for(auto c : s) {
            if(c == '(') {
                inBracket = true;
                key = "";
            }
            else if(c == ')') {
                inBracket = false;
                if(kn.find(key) != kn.end()) {
                    for(auto ch : kn[key]) ans += ch;
                }
                else ans += '?';
            }
            else if(inBracket) {
                key += c;
            }
            else {
                ans += c;
            }
        }

        return ans;
    }
};
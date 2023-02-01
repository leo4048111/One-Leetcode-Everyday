// https://leetcode.cn/problems/decode-the-message/

class Solution {
public:
    string decodeMessage(string key, string message) {
        char tb[26];
        map<char, bool> isParsed;
        char tmp = 'a';
        for(auto& c : key) {
            if(c == ' ') continue;
            if(!isParsed[c]){
                tb[c - 'a'] = tmp;
                tmp++;
                isParsed[c] = true;
            }
        }

        for(int i = 0; i < message.size(); i++) {
            if(message[i] == ' ') continue;
            message[i] = tb[message[i] - 'a'];
        }

        return message;
    }
};
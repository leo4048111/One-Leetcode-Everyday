// https://leetcode.cn/problems/counting-words-with-a-given-prefix/

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        for(auto word : words)
        {
            if(word.size() < pref.size()) continue;

            bool found = true;
            for(int i = 0; i < pref.size(); i++)
            {
                if(word[i] != pref[i]) {
                    found = false;
                    break;
                }
            }
            if(found)
                ans++;
        }

        return ans;
    }
};
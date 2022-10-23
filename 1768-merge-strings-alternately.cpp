// https://leetcode.cn/problems/merge-strings-alternately/

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0;
        string ans;
        while(i < word1.size() && i < word2.size())
        {
            ans += word1[i];
            ans += word2[i];
            i++;
        }

        if(i < word1.size()) ans += word1.substr(i, word1.size() - i);
        else if(i < word2.size()) ans += word2.substr(i, word2.size() - i);

        return ans;
    }
};
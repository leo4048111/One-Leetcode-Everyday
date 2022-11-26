// https://leetcode.cn/problems/expressive-words/

class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        int res = 0;
        for (string word : words) {
            if (check(s, word)) res++;
        } 
        return res;
    }
    
private:
    bool check(string s, string word) {
        int i = 0, j = 0;
        while (i < s.size() && j < word.size()) {
            if (s[i] != word[j]) return false; 
            
            char c = s[i];
            
            int cnts = 0;
            while (i < s.size() && s[i] == c) {
                i++; 
                cnts++;
            }
            
            int cntw = 0;
            while (j < word.size() && word[j] == c) {
                j++; 
                cntw++;
            }
            
            if (cnts < cntw) return false;
            if (cnts > cntw && cnts < 3) return false; 
        }
        return i == s.size() && j == word.size();
    }
};
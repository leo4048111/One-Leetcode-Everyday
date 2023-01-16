// https://leetcode.cn/problems/sentence-similarity-iii/

// this is a pasted solution
#define all(x) x.begin() ,x.end()
class Solution
{
public:
    bool areSentencesSimilar(string sentence1, string sentence2)
    {
        if(sentence1 == sentence2 || !sentence1.size() || !sentence2.size()) return true;
        if(sentence1.size() < sentence2.size()) swap(sentence1, sentence2);

        vector<string> v1, v2;
        stringstream s1(sentence1), s2(sentence2);
        string s;
        while(s1 >> s) v1.emplace_back(s);
        while(s2 >> s) v2.emplace_back(s);
        int l = -1, r = -1;
        while(l + 1 < v2.size() && v1[l + 1] == v2[l + 1]) l++;
        reverse(all(v1)), reverse(all(v2));
        while(r + 1 < v2.size() && v1[r + 1] == v2[r + 1]) r++;
        if(l + r + 2 >= (int)v2.size()) return true;
        return false;
    }
};
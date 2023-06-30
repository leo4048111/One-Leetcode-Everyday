// https://leetcode.cn/problems/circular-sentence/

class Solution {
public:
    bool isCircularSentence(string sentence) {
        int lastCh = sentence[sentence.size() - 1];

        string word;

        for(auto& c : sentence)
        {
            if(c != ' ')
            {
                word += c;
            }
            else {
                if(word.size() && (word[0] == lastCh)) {
                    lastCh = word[word.size() - 1];
                    word = "";
                } else return false;
            }
        }

        
        return word[0] == lastCh;
    }
};
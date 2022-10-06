// https://leetcode.cn/problems/three-equal-parts/

// my brainless TLE solution
class Solution {
public:
    const bool isSameBinStr(string s1, string s2)
    {
        int idx1 = 0, idx2 = 0;
        while((idx1 < s1.size() - 1) && s1[idx1] == '0') idx1++;
        while((idx2 < s2.size() - 1) && s2[idx2] == '0') idx2++;
        return s1.substr(idx1, s1.size() - idx1) == s2.substr(idx2, s2.size() - idx2);      
    }

    vector<int> threeEqualParts(vector<int>& arr) {
        string num;
        for(auto& n: arr) num += (char)(n + '0');

        for(int i = 0; i < num.size(); i++)
        {
            for(int j = i + 2; j < num.size(); j++)
            {
                string s1 = num.substr(0, i + 1);
                string s2 = num.substr(i + 1, j - i - 1);
                string s3 = num.substr(j, num.size() - j);
                if(isSameBinStr(s1, s2) && isSameBinStr(s2, s3)) return {i, j};
            }
        }

        return {-1, -1};
    }
};

// the smart solution
class Solution {
public:
    const bool isSameBinStr(string s1, string s2)
    {
        int idx1 = 0, idx2 = 0;
        while((idx1 < s1.size() - 1) && s1[idx1] == '0') idx1++;
        while((idx2 < s2.size() - 1) && s2[idx2] == '0') idx2++;
        return s1.substr(idx1, s1.size() - idx1) == s2.substr(idx2, s2.size() - idx2);      
    }

    int findSplitPoint(const string num, int suffix0, int oneCnt, const int head)
    {
        for(int i = head; i < num.size(); i++)
        {
            if(num[i] == '1')
            {
                if(--oneCnt < 0) return -1;
                if(!oneCnt && !suffix0) return i;
            }
            else if(oneCnt == 0 && --suffix0 == 0)
                return i;
        }

        return -1;
    }

    vector<int> threeEqualParts(vector<int>& arr) {
        string num;
        int cnt = 0;
        for(auto& n: arr) 
        {
            num += (char)(n + '0');
            if(n) cnt++;
        }
        if(!cnt) return {0, 2};
        if(cnt % 3) return {-1, -1};

        int i = num.size() - 1;
        while(i >= 0 && num[i] == '0') i--;
        int suffixZeroCnt = num.size() - i - 1;
        i = findSplitPoint(num, suffixZeroCnt, cnt / 3, 0);
        if(i == -1) return {-1, -1};
        int j = findSplitPoint(num, suffixZeroCnt, cnt / 3, i + 1);
        if(j == -1) return {-1, -1};
        string s1 = num.substr(0, i + 1);
        string s2 = num.substr(i + 1, j - i);
        string s3 = num.substr(j + 1, num.size() - j - 1);
        if(isSameBinStr(s1, s2) && isSameBinStr(s2, s3)) return {i, j + 1};
        else return {-1, -1};
    }
};

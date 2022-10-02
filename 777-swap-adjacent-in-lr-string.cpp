// https://leetcode.cn/problems/swap-adjacent-in-lr-string/

// my dogshit TLE backtrack solution 
class Solution {
public:
    unordered_map<string, bool> _smap;
    bool dfs(string start, const string end) {
        if(start == end) return true;
        _smap.insert(make_pair(start, true));
        bool result = false;
        for(int i = 0; i < start.size() - 1; i++)
        {
            if(start.substr(i, 2) == "XL" || start.substr(i, 2) == "RX")
            {
                swap(start[i], start[i + 1]);
                if(_smap.find(start) == _smap.end())
                    result |= dfs(start, end);
                swap(start[i], start[i + 1]);
            }

            if(result) return result;
        }

        return result;
    }

    bool canTransform(string start, string end) {
        return dfs(start, end);
    }
};

// AC solution
class Solution {
public:
    bool canTransform(string start, string end) {
        if(start.size() != end.size()) return false;
        vector<pair<char, int>> startCharIdx;
        vector<pair<char, int>> endCharIdx;
        for(int i = 0; i < start.size(); i++)
        {
            if(start[i] != 'X') startCharIdx.push_back(make_pair(start[i], i));
            if(end[i] != 'X') endCharIdx.push_back(make_pair(end[i], i));
        }

        if(startCharIdx.size() != endCharIdx.size()) return false;

        for(int i = 0; i < startCharIdx.size(); i++)
        {
            auto& p1 = startCharIdx[i];
            auto& p2 = endCharIdx[i];
            if(p1.first != p2.first) return false;
            if(p1.first == 'L' && (p1.second < p2.second)) return false;
            if(p1.first == 'R' && (p1.second > p2.second)) return false;
        }

        return true;
    }
};
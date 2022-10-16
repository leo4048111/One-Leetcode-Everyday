// https://leetcode.cn/problems/possible-bipartition/

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> d(n);
        for(auto& pair : dislikes)
        {
            d[pair[0] - 1].push_back(pair[1] - 1);
            d[pair[1] - 1].push_back(pair[0] - 1);
        }

        int colors[n];
        memset(colors, 0, sizeof(colors));

        function<bool(int, int)> dfs = [&](int idx, int color) -> bool {
            colors[idx] = color;
            for(auto& person : d[idx]) {
                if(!colors[person] && !dfs(person, 3 - color)) return false;
                if(colors[person] == color) return false;
            }

            return true;
        };

        for(int i = 0; i < n;i++)
        {
            if(!colors[i] && !dfs(i, 1)) return false;
        }

        return true;
    }
};
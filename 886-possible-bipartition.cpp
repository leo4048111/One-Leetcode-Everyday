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

// solution with union-find disjoint sets
class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);

        vector<vector<int>> graph(n);

        for(auto& pair : dislikes)
        {
            graph[pair[0] - 1].push_back(pair[1] - 1);
            graph[pair[1] - 1].push_back(pair[0] - 1);
        }

        function<int(int)> findAncestor = [&](int idx) -> int {
            int father = p[idx];
            if(father == p[idx]) return father;
            else return findAncestor(father);
        };

        function<void(int, int)> Union = [&](int idx1, int idx2) -> void{
            int a1 = findAncestor(idx1);
            int a2 = findAncestor(idx2);
            p[a1] = a2;
        };

        for(int i = 0; i < n; i++)
        {
            for(auto& dislikePerson : graph[i])
            {
                if(findAncestor(i) == findAncestor(dislikePerson)) return false;
                Union(dislikePerson, graph[i][0]);
            }
        }

        return true;
    }
};
// https://leetcode.cn/problems/count-servers-that-communicate/description/

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        vector<vector<bool>> visited(m + 1, vector<bool>(n + 1, false));

        function<void(int, int)> dfs = [&](int x, int y) {
            if(visited[x][y]) return;
            visited[x][y] = true;
            bool found = false;
            for(int i = 0; i < m; i++) {
                if(i == x) continue;
                if(grid[i][y]) {
                    found = true;
                    if(!visited[i][y])
                        dfs(i, y);
                }
            }

            for(int j = 0; j < n; j++) {
                if(j == y) continue;
                if(grid[x][j]) {
                    found = true;
                    if(!visited[x][j])
                        dfs(x, j);
                }
            }

            if(found) ans++;
        };

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j]) {
                    if(!visited[i][j])
                        dfs(i, j);
                }
            }
        }

        return ans;
    }
};
// https://leetcode.cn/problems/shortest-path-to-get-all-keys/

class Solution {
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    
    struct State {
        int x;
        int y;
        int key;
    };
    
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        // 先找到起点，以及钥匙的数量
        State start; 
        int keycnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '@') {
                    start.x = i;
                    start.y = j;
                    start.key = 0;
                }
                if (islower(grid[i][j])) {
                    keycnt++;
                }
            }
        }
        
        // BFS
        queue<State> q;
        q.push(start);
        int allkey = (1 << keycnt) - 1; // 表示所有钥匙都找到的状态
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(allkey + 1, false)));
        int step = 0;
        while (!q.empty()) {
            int qSize = q.size();
            for (int i = 0; i < qSize; i++) {
                State cur = q.front();
                q.pop();
                
                // 如果所有钥匙都找到
                if (cur.key == allkey) return step;
                
                // 遍历下一个状态
                for (int k = 0; k < 4; k++) {
                    int x = cur.x + dx[k], y = cur.y + dy[k];
                    if (x < 0 || y < 0 || x >= m || y >= n) continue;
                    
                    char c = grid[x][y];
                    int key = cur.key;
                    
                    if (c == '#') continue;
                    if (isupper(c) && (key >> (c - 'A') & 1) == 0) continue;
                    
                    if (islower(c)) {
                        key |= 1 << (c - 'a');
                    }
                    if (visited[x][y][key] == true) continue;
                    
                    visited[x][y][key] = true; 
                    q.push(State{x, y, key}); 
                } 
            }
            step++;
        }
        return -1;
    }
};
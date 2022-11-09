// https://leetcode.cn/problems/largest-plus-sign/

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> grid(n, vector<int>(n, 1));
        for (auto mine : mines) {
            int x = mine[0], y = mine[1];
            grid[x][y] = 0;
        }
        
        vector<vector<int>> up(n, vector<int>(n, 0));
        vector<vector<int>> down(n, vector<int>(n, 0));
        vector<vector<int>> left(n, vector<int>(n, 0));
        vector<vector<int>> right(n, vector<int>(n, 0));
        
        int cnt = 0;
        
        for (int i = 0; i < n; i++) {
            // left
            cnt = 0;
            for (int j = 0; j < n; j++) {
                cnt = grid[i][j] == 0 ? 0 : cnt + 1; 
                left[i][j] = cnt;
            } 
            // right
            cnt = 0;
            for (int j = n - 1; j >= 0; j--) {
                cnt = grid[i][j] == 0 ? 0 : cnt + 1; 
                right[i][j] = cnt;
            }
        }
        
        for (int j = 0; j < n; j++) {
            // up
            cnt = 0;
            for (int i = 0; i < n; i++) {
                cnt = grid[i][j] == 0 ? 0 : cnt + 1;
                up[i][j] = cnt; 
            }
            // down
            cnt = 0;
            for (int i = n - 1; i >= 0; i--) {
                cnt = grid[i][j] == 0 ? 0 : cnt + 1;
                down[i][j] = cnt;
            }
        }
        
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int cnt = min({up[i][j], down[i][j], left[i][j], right[i][j]});
                res = max(res, cnt);
            }
        } 
        
        return res;
    }
};
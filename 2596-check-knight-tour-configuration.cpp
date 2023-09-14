// https://leetcode.cn/problems/check-knight-tour-configuration/?envType=daily-question&envId=2023-09-13

class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        const int n = grid.size();
        const int dirX[] = {-1, -2, -2, -1, 1, 2, 2, 1};
        const int dirY[] = {-2, -1, 1, 2, 2, 1, -1, -2};
        int curX = 0, curY = 0;
        if(grid[curX][curY]) return false;

        for(int i = 0; i < n * n - 1; i++) {
            bool found = false;
            for(int j = 0; j < 8; j++) {
                int nextX = curX + dirX[j];
                int nextY = curY + dirY[j];
                if(nextX >= 0 && nextX < n && nextY >= 0 && nextY < n) {
                    if(grid[nextX][nextY] == i + 1) {
                        found = true;
                        curX = nextX;
                        curY = nextY;
                        break;
                    }
                }
            }

            if(!found) return false;
        }

        return true;
    }
};
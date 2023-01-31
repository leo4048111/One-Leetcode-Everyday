// https://leetcode.cn/problems/check-if-matrix-is-x-matrix/

class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++) {
            int diff = grid.size() - 1 - i;
            for(int j = 0; j < grid[i].size(); j++) {
                if(i == j || (j == diff)) {
                    if(!grid[i][j]) return false;
                }
                else if(grid[i][j]) return false;
            }
        }

        return true;
    }
};
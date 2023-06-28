// https://leetcode.cn/problems/ju-zhen-zhong-de-lu-jing-lcof/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

        function<bool(int, int, int)> dfs = [&](int row, int col, int wIdx) {
            if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size()) return false;

            if(board[row][col] != word[wIdx]) return false;

            visited[row][col] = true;

            if(wIdx == word.size() - 1) return true;

            int dirX[] = {-1, 0, 1, 0};
            int dirY[] = {0, 1, 0, -1};
            bool result = false;
            for(int i = 0; i < 4; i++)
            {
                int newRow = row + dirX[i];
                int newCol = col + dirY[i];

                result |= dfs(newRow, newCol, wIdx + 1);

                if(result) return result;
            }

            return result;
        };

        for(int row = 0; row < board.size(); row++)
        {
            for(int col = 0; col < board.size(); col++)
            {
                    visited = vector<vector<bool>>(board.size(), vector<bool>(board[0].size(), false));
                    bool result = dfs(row, col, 0);

                    if(result) return result;
            }
        }
        
        return false;
    }
};
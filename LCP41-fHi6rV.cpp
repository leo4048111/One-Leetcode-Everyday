// https://leetcode.cn/problems/fHi6rV/

// testcases passed 153/154, i give up

class Solution {
public:
    int flipChess(vector<string>& chessboard) {
        function<int(vector<string>&, int, int, vector<vector<bool>>&)> dfs = [&](vector<string>& board, int x, int y, vector<vector<bool>>& visited) -> int
        {
            visited[x][y] = true;
            int res = 0;
            int dirX[] = {-1, 0, 1};
            int dirY[] = {-1, 0, 1};

            for(int i = 0; i < 3; i++)
            {
                for(int j = 0; j < 3; j++)
                {
                    int cnt = 1;

                    int newX = x + dirX[i] * cnt;
                    int newY = y + dirY[j] * cnt;
                    int nextBlackCnt = 0;
                    
                    while((newX >= 0) && (newY >= 0) && (newX < board.size()) && (newY < board[0].size()) && ((newX != x) || (newY != y)))
                    {
                        if(board[newX][newY] == '.') break;
                        if(visited[newX][newY]) break;
                        else if(board[newX][newY] == 'X') {
                            nextBlackCnt = cnt;
                        }

                        cnt++;
                        newX += dirX[i];
                        newY += dirY[j];
                    }

                    for(int tmp = 1; tmp < nextBlackCnt; tmp++)
                    {
                        newX = x + dirX[i] * tmp;
                        newY = y + dirY[j] * tmp;

                        if(board[newX][newY] == 'O') {
                            res++;
                            board[newX][newY] = 'X';
                            res += dfs(board, newX, newY, visited);
                        }
                    }
                }
            }

            return res;
        };

        int ans = INT_MIN;

        for(int row = 0; row < chessboard.size(); row++)
        {
            for(int col = 0; col < chessboard[0].size(); col++)
            {
                if(chessboard[row][col] == '.') // blank
                {
                    vector<string> tmp = chessboard;
                    tmp[row][col] = 'X';
                    vector<vector<bool>> visited(chessboard.size(), vector<bool>(chessboard[0].size(), false));
                    ans = max(ans, dfs(tmp, row, col, visited));
                }
            }
        }

        return ans;
    }
};
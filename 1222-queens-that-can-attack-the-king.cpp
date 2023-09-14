// https://leetcode.cn/problems/queens-that-can-attack-the-king/description/?envType=daily-question&envId=2023-09-14

class Solution {
public:
    struct VectorComparer {
    bool operator() (const std::vector<int>& lhs, const std::vector<int>& rhs) const {
        if (lhs[0] != rhs[0]) {
            return lhs[0] < rhs[0];
        }
        return lhs[1] < rhs[1];
    }
    };

    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> ans;
        vector<vector<int>> mat(8, vector<int>(8, 0));
        set<vector<int>, VectorComparer> s;

        for(auto& q : queens) {
            mat[q[0]][q[1]] = 1;
        }

        mat[king[0]][king[1]] = 2;
        
        const int dirX[] = {-1, -1, -1, 0, 1, 1, 1, 0};
        const int dirY[] = {-1, 0, 1, 1, 1, 0, -1, -1};

        for(int i = 0; i < 8; i++) {
            int nextX = king[0] + dirX[i], nextY = king[1] + dirY[i];
            while(nextX >= 0 && nextX < 8 && nextY >= 0 && nextY < 8) {
                if(mat[nextX][nextY] == 1) {
                    s.insert({nextX, nextY});
                    break;
                }
                nextX += dirX[i];
                nextY += dirY[i];
            }
        }

        for(auto& item : s) {
            ans.push_back(item);
        }

        return ans;
    }
};
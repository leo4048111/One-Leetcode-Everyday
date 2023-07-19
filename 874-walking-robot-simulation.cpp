// https://leetcode.cn/problems/walking-robot-simulation/

class Solution
{
public:
    bool inside(int num, int pos1, int pos2)
    {
        if (num >= pos1 && num <= pos2)
            return true;
        if (num >= pos2 && num <= pos1)
            return true;

        return false;
    }

    int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
    {
        int dirX[] = {0, 1, 0, -1};
        int dirY[] = {1, 0, -1, 0};
        // turn right ++, turn left --

        int dirIdx = 0;
        int posX = 0, posY = 0;

        int ans = 0;

        set<pair<int, int>> st;
        for (auto &obstacle : obstacles)
        {
            st.emplace(obstacle[0], obstacle[1]);
        }

        for (auto &cmd : commands)
        {
            switch (cmd)
            {
            case -2:
                dirIdx = (dirIdx - 1 < 0) ? 3 : dirIdx - 1;
                break;
            case -1:
                dirIdx = (dirIdx + 1 > 3) ? 0 : dirIdx + 1;
                break;
            default:
            {
                for (int i = 0; i < cmd; i++)
                {
                    int tmpX = posX + dirX[dirIdx];
                    int tmpY = posY + dirY[dirIdx];
                    if (st.count({tmpX, tmpY}))
                        break;

                    posX = tmpX;
                    posY = tmpY;
                    ans = max(ans, posX * posX + posY * posY);
                }
                break;
            }
            }
        }

        return ans;
    }
};
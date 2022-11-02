// https://leetcode.cn/problems/coordinate-with-maximum-network-quality/

class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        int maxSignal = INT_MIN;
        int ansX, ansY;
        for(int x = 50; x >= 0; x--)
        {
            for(int y = 50; y >= 0; y--)
            {
                int signal = 0;
                for(auto& tower : towers)
                {
                    int distance = (tower[0] - x) * (tower[0] - x) + (tower[1] - y) * (tower[1] - y);
                    if(distance > radius * radius) continue;

                    signal += tower[2] / (1 + sqrt(distance));
                }
                if(signal >= maxSignal)
                {
                    maxSignal = signal;
                    ansX = x;
                    ansY = y;
                } 
            }
        }

        return {ansX, ansY};
    }
};
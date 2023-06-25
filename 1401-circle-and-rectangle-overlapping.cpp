// https://leetcode.cn/problems/circle-and-rectangle-overlapping/

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int dx = 0, dy = 0;

        if(x1 > xCenter || x2 < xCenter)
            dx = min(abs(x1 - xCenter), abs(xCenter - x2));

        if(y1 > yCenter || y2 < yCenter)
            dy = min(abs(y1 - yCenter), abs(yCenter - y2));

        return dx * dx + dy * dy <= radius * radius;
    }
};
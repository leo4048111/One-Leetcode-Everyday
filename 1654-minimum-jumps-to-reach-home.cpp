// https://leetcode.cn/problems/minimum-jumps-to-reach-home/description/

class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        map<int, bool> cannotVisit;
        for(auto& pos : forbidden) {
            cannotVisit[pos] = true;
        }
        cannotVisit[0] = true;
        queue<tuple<int, int, bool>> q;

        q.emplace(0, 0, true);

        while(!q.empty()) {
            auto [pos, step, canGoBack] = q.front();
            q.pop();
            if(pos == x) return step;

            int nextPos = pos + a;
            if(!cannotVisit[nextPos] && nextPos <= 6000) {
                q.emplace(nextPos, step + 1, true);
                cannotVisit[nextPos] = true;
            }

            if(canGoBack) {
                int nextPos = pos - b;
                if(nextPos >= 0 && !cannotVisit[nextPos]) {
                    q.emplace(nextPos, step + 1, false);
                }
            }
        }

        return -1;
    }
};
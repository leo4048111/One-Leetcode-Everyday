// https://leetcode.cn/problems/maximum-enemy-forts-that-can-be-captured/

class Solution {
public:
    int captureForts(vector<int>& forts) {
        int ans = 0, left = 0, tmp = 0;

        for(auto& f : forts) {
            if(f != 0) {
                if(f == -left) {
                    ans = max(ans, tmp);
                }

                tmp = 0;
                left = f;
            } else tmp++;
        }

        return ans;
    }
};
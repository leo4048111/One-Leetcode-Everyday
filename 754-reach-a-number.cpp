// https://leetcode.cn/problems/reach-a-number/

class Solution {
public:
    int reachNumber(int target) {
        if(target < 0) return reachNumber(target * -1);
        int l = 1, r = target;

        int t = target * 2;
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(1 + mid >= t / mid) r = mid;
            else l = mid + 1;
        }

        int dis = (1 + l) * l / 2;
        while(dis < target || (dis - target) % 2) {
            ++l;
            dis += l;
        }

        return l;
    }
};
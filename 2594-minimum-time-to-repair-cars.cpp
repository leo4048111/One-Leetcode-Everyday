// https://leetcode.cn/problems/minimum-time-to-repair-cars/description/?envType=daily-question&envId=2023-09-07

class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        typedef long long ll;
        int n = ranks.size();
        ll border;//二分右边界
        int maximum = INT_MIN;
        for (int i = 0; i < n; i++) maximum = max(maximum, ranks[i]);
        border = (ll)maximum * (ll)cars * (ll)cars;//最大的r乘n^2
        ll left = 1, right = border;
        ll mid = 0;
        while (left <= right) {//我习惯闭区间
            mid = left + (right - mid) / 2;
            ll sum = 0;
            for (int i = 0; i < n; i++) {//
                ll temp = (ll)sqrt(mid / ranks[i]);
                sum += temp;
            }
            if (sum < cars) left = mid + 1;
            else right = mid - 1;
        }
        return left;
    }
};


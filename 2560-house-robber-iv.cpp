// https://leetcode.cn/problems/house-robber-iv/description/?envType=daily-question&envId=2023-09-19

class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        auto [t1, t2] = minmax_element(nums.begin(), nums.end());
        int l = *t1, r = *t2;
        auto judge = [&](int val) -> bool {
            int cnt = 0;
            for(int i = 0; i < nums.size() && cnt < k;) {
                if(nums[i] <= val) {
                    i+=2;
                    cnt++;
                } else i++;
            }

            return cnt == k;
        };

        while(l < r) {
            int mid = l + (r - l) / 2;

            if(judge(mid)) {
                r = mid;
            }else {
                l = mid + 1;
            }
        }

        return l;
    }
};
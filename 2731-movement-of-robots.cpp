// https://leetcode.cn/problems/movement-of-robots/description/?envType=daily-question&envId=2023-10-10

constexpr size_t mod = 1e9 + 7;
class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        for (size_t i = 0; i < s.size(); i++)
        {
            nums[i] += (s[i] == 'R' ? d : -d);
        }
        ranges::sort(nums);
        auto ans = 0ll;
        for (size_t i = 1; i < nums.size(); i++)
        {
            ans += (1ll * nums[i] - nums[i - 1]) * i % mod * (nums.size() - i) % mod;
        }
        return ans % mod;
    }
};
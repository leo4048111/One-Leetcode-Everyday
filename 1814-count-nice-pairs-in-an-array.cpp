// https://leetcode.cn/problems/count-nice-pairs-in-an-array/

class Solution {
public:
    int rev(int num)
    {
        int ans = 0;
        while(num) {
            ans *= 10;
            ans += num % 10;
            num /= 10;
        }

        return ans;
    }

    int countNicePairs(vector<int>& nums) {
        map<long long, long long> m;
        long long ans = 0; 
        long long mod = 1e9 + 7;

        for(auto& num : nums)
        {
            m[num - rev(num)]++;
        }

        for(auto& pair : m) {
            ans = (ans % mod + (pair.second - 1) * pair.second / 2 % mod) % mod;
        }

        return ans;
    }
};
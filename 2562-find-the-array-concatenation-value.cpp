class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        using ll = long long;

        ll ans = 0;
        int n = nums.size();
        int left = 0, right = n - 1;

        while(left <= right) {
            if(left == right) ans += nums[left];
            else {
                string tmp = to_string(nums[left]) + to_string(nums[right]);

                ans += atoi(tmp.c_str());
            }

            left++;
            right--;
        }

        return ans;
    }
};
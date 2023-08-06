// https://leetcode.cn/problems/3sum-closest/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = INT_MIN;
        int diff = INT_MAX;
        for(int i = 0; i < nums.size(); i++) {
            int left = i + 1, right = nums.size() - 1;

            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if(abs(sum - target) < diff) {
                    diff = abs(sum - target);
                    ans = sum;
                }
                if(sum > target) right--;
                else if(sum < target) left++;
                else break;
            }
        }

        return ans;
    }
};
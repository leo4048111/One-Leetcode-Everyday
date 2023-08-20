// https://leetcode.cn/problems/1fGaJU/description/

class Solution {
public:
    struct cmp {
        bool operator()(const vector<int>& nums1, const vector<int>& nums2) const {
            auto tmp1 = nums1;
            auto tmp2 = nums2;
            sort(tmp1.begin(), tmp1.end());
            sort(tmp2.begin(), tmp2.end());
            for(int i = 0; i < 3; i++) {
                if(tmp1[i] != tmp2[i]) return true;
            }

            return false;
        }
    };

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        if(nums.size() < 3) return ans;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size() - 2; i++) {
            if(nums[i] > 0) break;
            int left = i + 1, right = nums.size() - 1;
            int n = nums.size();
            while((left < nums.size()) && (right >= 0) && (left < right)) {
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == 0) {
                    vector<int> tmp = {nums[i], nums[left], nums[right]};
                    left++;
                    right--;
                    while((left < n) && nums[left] == nums[left - 1]) left++;
                    while((right >= 0) && nums[right] == nums[right + 1])right--;
                    ans.push_back(tmp);
                } else if(sum < 0){
                    left++;
                } else right--;
            }

            while(i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;
        }

        return ans;
    }
}; 
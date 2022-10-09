// https://leetcode.cn/problems/advantage-shuffle/

// O(nlogn) greedy still TLE idk why
class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        vector<int> tmp = nums1;
        sort(tmp.begin(), tmp.end());
        for(auto& n : nums2)
        {
            int left = 0;
            int right = tmp.size();
            while(left < right)
            {
                int mid = (left + right) / 2;
                if(tmp[mid] <= n) left = mid + 1;
                else right = mid;
            }

            int mid = (left + right) / 2;
            if(mid >= tmp.size() || tmp[mid] <= n)
            {
                ans.push_back(tmp[0]);
                tmp.erase(tmp.begin());
            }
            else
            {
                ans.push_back(tmp[mid]);
                tmp.erase(tmp.begin() + mid);
            }
        }

        return ans;
    }
};

// Smart AC greedy implementation
class Solution {
public:
    vector<int> advantageCount(vector<int> &nums1, vector<int> &nums2) {
        int n = nums1.size();
        vector<int> ans(n);
        int ids[n];
        sort(nums1.begin(), nums1.end());
        iota(ids, ids+n, 0);
        sort(ids, ids+n, [&](int i, int j){ return nums2[i] < nums2[j]; });
        int left = 0, right = n - 1;
        for(auto& n : nums1)
        {
            ans[n > nums2[ids[left]] ? ids[left++] : ids[right--]] = n;
        }

        return ans;
    }
};

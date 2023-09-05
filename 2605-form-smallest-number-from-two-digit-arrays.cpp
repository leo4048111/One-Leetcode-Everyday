// https://leetcode.cn/problems/form-smallest-number-from-two-digit-arrays/description/?envType=daily-question&envId=2023-09-05

class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> m;
        for(auto n : nums1) m[n]++; 
        for(auto n : nums2) m[n]+=2;

        // m[n] == 1 只在nums1出现
        // m[n] == 2 只在nums2出现
        // m[n] == 3 在两个都出现

        int min1 = INT_MAX, min2 = INT_MAX;
        for(int k = 1; k < 10; k++) {
            auto v = m[k];
            switch(v) {
                case 3 : return k;
                case 2 : {
                    min2 = min(min2, k);
                    break;
                }
                case 1: {
                    min1 = min(min1, k);
                    break;
                }
            }
        }

        return min1 > min2 ? 10 * min2 + min1 : 10 * min1 + min2;
    }
};
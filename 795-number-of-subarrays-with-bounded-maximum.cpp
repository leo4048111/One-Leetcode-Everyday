// https://leetcode.cn/problems/number-of-subarrays-with-bounded-maximum/

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int j = -1, temp = 0, ans = 0;
        for(int i = 0; i < A.size(); i++) {
            if(A[i] > R)
                j = i;
            if(A[i] >= L)
                temp = i - j;
            ans += temp;
        }
        return ans;
    }
};
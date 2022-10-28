// https://leetcode.cn/problems/sum-of-subarray-minimums/

class Solution {
public:
    const long long MOD = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        int N = arr.size();
        stack<int> s;

        vector<int> left(N, -1);
        for(int i = 0; i < N; i++)
        {
            while(!s.empty() && arr[s.top()] >= arr[i]) s.pop();
            if(!s.empty()) left[i] = s.top();
            s.push(i);
        }

        vector<int> right(N, N);
        while(!s.empty()) s.pop();
        for(int i = N-1;i>=0;i--)
        {
            while(!s.empty() && arr[s.top()] > arr[i]) s.pop();
            if(!s.empty()) right[i] = s.top();
            s.push(i);
        }

        long long ans = 0;
        for(int i = 0; i < N; i++)
        {
            ans = (ans % MOD + (arr[i] % MOD) * ((i - left[i]) % MOD) * ((right[i] - i) % MOD)) ;
        }

        return ans % MOD;
    }
};
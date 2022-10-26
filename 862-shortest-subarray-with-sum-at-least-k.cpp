// https://leetcode.cn/problems/shortest-subarray-with-sum-at-least-k/

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int> myque;
        vector<long long> sum(n+1);
        sum[0]=0;
        for(int i=1;i<=n;i++){
            sum[i]=sum[i-1]+nums[i-1];
        }

        int ans=INT_MAX;
        for(int i=0;i<sum.size();i++){
            while(!myque.empty() && sum[myque.back()]>=sum[i]){
                myque.pop_back();
            }

            while(!myque.empty() && sum[i]-sum[myque.front()]>=k){
                ans=min(ans,i-myque.front());
                myque.pop_front();
            }
            myque.push_back(i);
        }

        return ans==INT_MAX?-1:ans;
    }
};
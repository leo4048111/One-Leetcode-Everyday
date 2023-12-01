// https://leetcode.cn/problems/first-completely-painted-row-or-column/?envType=daily-question&envId=2023-12-01

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size(),res=m*n;
        unordered_map<int,int> mp;
        for(int i=0;i<res;i++){
            mp[arr[i]]=i;
        }
        vector<int> rows(m),cols(n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                rows[i]=max(rows[i],mp[mat[i][j]]);
                cols[j]=max(cols[j],mp[mat[i][j]]);
            }
        }
        for(int &row:rows)res=min(res,row);
        for(int &col:cols)res=min(res,col);
        return res;
    }
};
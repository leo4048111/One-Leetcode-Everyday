// https://leetcode.cn/problems/avoid-flood-in-the-city/?envType=daily-question&envId=2023-10-13

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n=rains.size();
        set<int> a;
        unordered_map<int,int>b;
        for(int i=0;i<n;i++){
            if(rains[i]){
                if(!b.count(rains[i])){
                    b[rains[i]]=i;
                }
                else{
                    auto t=a.upper_bound(b[rains[i]]);
                    if(t==a.end())return {};
                    rains[*t]=rains[i];
                    a.erase(*t);
                    b[rains[i]]=i;
                }
                rains[i]=-1;
            }
            else{
                a.insert(i);
                rains[i]=1;
            }
        }
        return rains;
    }
};
// https://leetcode.cn/problems/maximum-units-on-a-truck/

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n=boxTypes.size(), s=0, i=0;
        sort(boxTypes.begin(), boxTypes.end(), [&](const vector<int> &a, const vector<int> &b){
            return a[1]>b[1];
        });
        while(truckSize && i<n){
            auto b = boxTypes[i];
            if(truckSize > b[0]){
                s += b[0] * b[1];
                truckSize -= b[0];
            }else{
                s += truckSize * b[1];
                break;
            }
            i++;
        }
        return s;
    }
};
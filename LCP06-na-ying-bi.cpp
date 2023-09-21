// https://leetcode.cn/problems/na-ying-bi/?envType=daily-question&envId=2023-09-20

class Solution {
public:
    int minCount(vector<int>& coins) {
        int ans = 0;

        for(auto& coin : coins) {
            ans += coin / 2 + coin % 2;
        }

        return ans;
    }
};
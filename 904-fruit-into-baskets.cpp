// https://leetcode.cn/problems/fruit-into-baskets/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0;
        int right = 0;
        int N = fruits.size();
        int type1 = fruits[left];
        int type2 = fruits[right];
        int ans = 0;
        while(right < N)
        {
            if(fruits[right] == type1 || fruits[right] == type2) {
                ans = max(ans, right - left + 1);
                right++;
            }
            else {
                left = right - 1;
                type1 = fruits[left];
                while(left > 0 && fruits[left-1] == type1) left--;
                type2 = fruits[right];
                ans = max(ans, right - left + 1);
            }
        }

        return ans;
    }
};
// https://leetcode.cn/problems/can-place-flowers/description/?envType=daily-question&envId=2023-09-29

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len = flowerbed.size();

        for(int i = 0; i < len; i++) {
            if(n == 0) break;

            if((i == 0 || flowerbed[i - 1] == 0) && flowerbed[i] == 0 && (i == len - 1 || flowerbed[i + 1] == 0)) {
                n--;
                flowerbed[i] = 1;
            }
        }

        return n == 0;
    }
};
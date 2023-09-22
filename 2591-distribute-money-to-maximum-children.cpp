// https://leetcode.cn/problems/distribute-money-to-maximum-children/description/?envType=daily-question&envId=2023-09-22

class Solution {
public:
    int distMoney(int money, int children) {
        if(money < children) return -1;

        if(money == children * 8) return children;
        if(money > children * 8) return children - 1;
        if(money == (children * 8 - 4)) return children - 2;

        return (money - children) / 7;
    }
};
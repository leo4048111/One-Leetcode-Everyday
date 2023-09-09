// https://leetcode.cn/problems/calculate-delayed-arrival-time/description/?envType=daily-question&envId=2023-09-08

class Solution {
public:
    int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
        return (arrivalTime + delayedTime) % 24;
    }
};
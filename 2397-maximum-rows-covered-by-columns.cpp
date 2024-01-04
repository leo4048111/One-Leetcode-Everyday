// https://leetcode.cn/problems/maximum-rows-covered-by-columns/description/?envType=daily-question&envId=2024-01-04

class Solution {
public:
    int bitCount(int num) {
        int cnt = 0;

        while(num) {
            cnt += num % 2;
            num /= 2;
        }

        return cnt;
    }

    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        vector<int> nums;

        for(int i = 0; i < matrix.size(); i++) {
            int num = 0;
            for(int j = 0; j < matrix[i].size(); j++) {
                num = num *2 + matrix[i][j];
            }
            nums.push_back(num);
        }

        int ans = 0;
        for(int i = 0; i < (1 << matrix[0].size()); i++) {
            if(bitCount(i) != numSelect) continue;
            int tmp = 0;
            for(auto& num : nums) {
                if((num & i) == num) tmp++;
            }

            ans = max(ans, tmp);
        }

        return ans;
    }
};
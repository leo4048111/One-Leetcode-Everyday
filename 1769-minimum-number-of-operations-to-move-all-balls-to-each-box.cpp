// https://leetcode.cn/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> res(n);
        
        int pre = 0;
        int cnt = 0; 
        for (int i = 1; i < n; i++) {
            if (boxes[i - 1] == '1') cnt++;
            res[i] = pre + cnt;
            pre += cnt;
        }
        
        pre = 0, cnt = 0;
        for (int i = n - 2; i >= 0; i--) {
            if (boxes[i + 1] == '1') cnt++;
            res[i] += pre + cnt;
            pre += cnt;
        }
        
        return res;
    }
};
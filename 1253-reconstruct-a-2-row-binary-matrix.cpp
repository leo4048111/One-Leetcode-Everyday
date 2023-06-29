// https://leetcode.cn/problems/reconstruct-a-2-row-binary-matrix/

class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        vector<vector<int>> ans(2, vector<int>(colsum.size(), 0));

        for(int i = 0; i < colsum.size(); i++)
        {
            if(colsum[i] == 0) {
                ans[0][i] = ans[1][i] = 0;
            }
            else if(colsum[i] == 2) {
                ans[0][i] = ans[1][i] = 1;
                upper--;
                lower--;
            }
            else {
                if(upper > lower) {
                    ans[0][i] = 1;
                    ans[1][i] = 0;
                    upper--;
                }
                else {
                    ans[0][i] = 0;
                    ans[1][i] = 1;
                    lower--;
                }
            }
        }

        if(upper || lower) {
            return vector<vector<int>>();
        }

        return ans;
    }
};
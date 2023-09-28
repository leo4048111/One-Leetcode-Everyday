// https://leetcode.cn/problems/number-of-flowers-in-full-bloom/description/?envType=daily-question&envId=2023-09-28

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
      map<int, int> m;

      for(auto& f : flowers) {
        m[f[0]]++;
        m[f[1] + 1]--;
      }

      for(auto& p : people) m[p];

      int total = 0;
      for(auto& [x, y] : m) {
          y = (total += y);
      }

      for(auto& p : people) p = m[p];

      return people;
    }
};
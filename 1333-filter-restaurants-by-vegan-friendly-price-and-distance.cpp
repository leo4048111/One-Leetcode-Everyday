// https://leetcode.cn/problems/filter-restaurants-by-vegan-friendly-price-and-distance/description/?envType=daily-question&envId=2023-09-27

class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<tuple<int, int>> ans;

        for(auto& r : restaurants) {
            if(veganFriendly) {
                if(r[2]) {
                    if(r[3] <= maxPrice && r[4] <= maxDistance) {
                        ans.push_back({r[0], r[1]});
                    }
                }
            }
            else {
                if(r[3] <= maxPrice && r[4] <= maxDistance) {
                    ans.push_back({r[0], r[1]});
                }
            }
        }

        sort(ans.begin(), ans.end(), [&](tuple<int, int> l, tuple<int, int> r) {
            if(get<1>(l) != get<1>(r))
                return get<1>(l) > get<1>(r);

            return get<0>(l) > get<0>(r);
        });
        
        vector<int> ret;
        for(auto& a : ans) {
            ret.push_back(get<0>(a));
        }

        return ret;
    }
};
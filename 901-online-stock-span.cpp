// https://leetcode.cn/problems/online-stock-span/

class StockSpanner {
public:
    stack<tuple<int, int>> s;
    int curDay_{0};

    StockSpanner() {
        
    }
    
    int next(int price) {
        int ans = 1;
        if(s.empty()) {
            s.push({price, ans});
            return ans;
        }

        while(s.size() && get<0>(s.top()) <= price)
        {
            ans += get<1>(s.top());
            s.pop();
        }

        s.push({price, ans});

        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// https://leetcode.cn/problems/online-stock-span/

class StockSpanner {
public:
    vector<int> _prices;
    int _ans {1};
    StockSpanner() {

    }
    
    int next(int price) {
        _prices.push_back(price);
        if(_prices.size() == 1) return _ans;
        if(price >= _prices[_prices.size() - 2]) _ans++;
        else _ans = 1;

        return _ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// https://leetcode.cn/problems/stock-price-fluctuation/?envType=daily-question&envId=2023-10-08

typedef pair<int, int> pii;
class StockPrice {
public:
    struct cmp1 {
        bool operator()(pii a, pii b) {
            return a.second < b.second;
        }
    };
    struct cmp2 {
        bool operator()(pii a, pii b) {
            return a.second > b.second;
        }
    };

    priority_queue<pii, vector<pii>, cmp1> q1;// 大顶堆
    priority_queue<pii, vector<pii>, cmp2> q2;// 小顶堆
    unordered_map<int, int> mp;// 正确股价[时间戳, 价格]
    int cur;// 最新时间戳

    StockPrice() {
        cur = 0;
    }
    
    void update(int timestamp, int price) {
        if(timestamp > cur) cur = timestamp;
        mp[timestamp] = price;
        q1.push({timestamp, price});
        q2.push({timestamp, price});
    }
    
    int current() {
        return mp[cur];
    }

    // 堆里可能有错误价格，在mp里找正确价格
    int maximum() {
        while(q1.size()) {
            pii t = q1.top();
            if(mp[t.first] == t.second) return t.second;// 找到了正确价格就返回，不删掉
            q1.pop();// 删掉错误价格
        }
        return 0;
    }
    
    int minimum() {
        while(q2.size()) {
            pii t = q2.top();
            if(mp[t.first] == t.second) return t.second;// 找到了正确价格就返回，不删掉
            q2.pop();// 删掉错误价格
        }
        return 0;
    }
};
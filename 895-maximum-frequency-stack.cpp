// https://leetcode.cn/problems/maximum-frequency-stack/

class FreqStack {
    struct cmp {
        bool operator() (vector<int> &a, vector<int> &b) {
            if (a[1] == b[1]) {
                return a[2] < b[2]; 
            } 
            return a[1] < b[1];
        };
    };
public:
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++;
        time++;
        q.push({val, freq[val], time});
    }
    
    int pop() {
        auto t = q.top();
        q.pop();
        int val = t[0];
        freq[val]--;
        return val;
    }
    
private:
    unordered_map<int, int> freq;
    
    priority_queue<vector<int>, vector<vector<int>>, cmp> q; 
    
    int time = 0;
};
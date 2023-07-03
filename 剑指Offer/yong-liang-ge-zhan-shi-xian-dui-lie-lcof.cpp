// https://leetcode.cn/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/

class CQueue {
public:
        stack<int> s1;
        stack<int> s2;
    CQueue() {
    }
    
    void appendTail(int value) {
        s1.push(value);
    }
    
    int deleteHead() {
        if(s1.empty()) return -1;
        while(s1.size()) {
            s2.push(s1.top());
            s1.pop();
        }

        int x = s2.top();
        s2.pop();
        while(s2.size()) {
            s1.push(s2.top());
            s2.pop();
        }

        return x;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
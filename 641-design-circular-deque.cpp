// https://leetcode.cn/problems/design-circular-deque/description/

class MyCircularDeque {
public:
    deque<int> dq_;
    int capacity_;

    MyCircularDeque(int k) {
        capacity_ = k;
    }
    
    bool insertFront(int value) {
        if(dq_.size() == capacity_) return false;
        dq_.push_front(value);
        return true;
    }
    
    bool insertLast(int value) {
        if(dq_.size() == capacity_) return false;
        dq_.push_back(value);
        return true;
    }
    
    bool deleteFront() {
        if(dq_.empty()) return false;
        dq_.pop_front();
        return true;
    }
    
    bool deleteLast() {
        if(dq_.empty()) return false;
        dq_.pop_back();
        return true;
    }
    
    int getFront() {
        if(dq_.empty()) return -1;

        return dq_.front();
    }
    
    int getRear() {
        if(dq_.empty()) return -1;

        return dq_.back();
    }
    
    bool isEmpty() {
        return dq_.empty();
    }
    
    bool isFull() {
        return dq_.size() == capacity_;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
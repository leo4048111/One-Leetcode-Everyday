// https://leetcode.cn/problems/dui-lie-de-zui-da-zhi-lcof/

class MaxQueue
{
public:
    queue<int> q;
    deque<int> dq;
    MaxQueue()
    {
    }

    int max_value()
    {
        if (dq.size())
            return dq.front();

        return -1;
    }

    void push_back(int value)
    {
        q.push(value);

        while (dq.size() && dq.back() < value)
            dq.pop_back();

        dq.push_back(value);
    }

    int pop_front()
    {
        if (q.size())
        {
            int x = q.front();
            q.pop();

            if (dq.front() == x)
                dq.pop_front();

            return x;
        }

        return -1;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
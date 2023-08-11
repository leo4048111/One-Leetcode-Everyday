// https://leetcode.cn/problems/my-calendar-iii/description/

class MyCalendarThree {
public:
    map<int, int> schedule_;
    MyCalendarThree() {

    }
    
    int book(int startTime, int endTime) {
        schedule_[startTime]++;
        schedule_[endTime]--;

        int cnt = 0;
        int ans = 0;

        for(auto& s : schedule_)
        {
            cnt += s.second;
            ans = max(cnt, ans);
        }

        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */
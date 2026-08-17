// 732. My Calendar III
// Difficulty: Hard
// https://leetcode.com/problems/my-calendar-iii/
// Runtime: 38 ms (beats —)
// Memory: 33.1 MB (beats —)
// Submitted: 2026-08-17

class MyCalendarThree {
public:
    map<int, int> timeline;

    MyCalendarThree() {}

    int book(int startTime, int endTime) {
        timeline[startTime]++;
        timeline[endTime]--;
        int intersection = 0, k = 0;
        for (auto t : timeline)
            k = max(k, intersection += t.second);
        return k;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */

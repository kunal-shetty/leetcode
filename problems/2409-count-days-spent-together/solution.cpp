// 2409. Count Days Spent Together
// Difficulty: Easy
// https://leetcode.com/problems/count-days-spent-together/
// Runtime: 0 ms (beats 100.0%)
// Memory: 8.1 MB (beats 20.0%)
// Submitted: 2026-10-24

class Solution {
public:
    int convertToDays(string s) {
        vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int month = stoi(s.substr(0, 2));
        int total = stoi(s.substr(3, 2));

        for (int i = 0; i < month - 1; i++)
            total += days[i];

        return total;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        string start = max(arriveAlice, arriveBob);
        string end = min(leaveAlice, leaveBob);

        if (start > end)
            return 0;

        return convertToDays(end) - convertToDays(start) + 1;
    }
};

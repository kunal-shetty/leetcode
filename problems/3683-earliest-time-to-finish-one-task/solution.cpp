// 3683. Earliest Time to Finish One Task
// Difficulty: Easy
// https://leetcode.com/problems/earliest-time-to-finish-one-task/
// Runtime: 7 ms (beats —)
// Memory: 38.3 MB (beats —)
// Submitted: 2026-06-06

class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int earliest = INT_MAX;
        for(auto task : tasks){
            earliest = min(earliest, task[0] + task[1]);
        }
        return earliest;
    }
};

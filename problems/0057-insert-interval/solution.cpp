// 57. Insert Interval
// Difficulty: Medium
// https://leetcode.com/problems/insert-interval/
// Runtime: 0 ms (beats —)
// Memory: 21.7 MB (beats —)
// Submitted: 2026-04-01

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;

        for(int i = 0; i < intervals.size(); i++){
            if(res.empty() || res.back()[1] < intervals[i][0])
                res.push_back(intervals[i]);
            else
                res.back()[1] = max(res.back()[1], intervals[i][1]);
        }

        return res;
    }
};

// 4056. Number of Intersecting Interval Pairs I
// Difficulty: Easy
// https://leetcode.com/problems/number-of-intersecting-interval-pairs-i/
// Runtime: 7 ms (beats —)
// Memory: 36.3 MB (beats —)
// Submitted: 2026-09-20

class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int res = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(max(intervals[i][0], intervals[j][0]) <= min(intervals[i][1], intervals[j][1])) res++;
            }
        }
        return res;
    }
};

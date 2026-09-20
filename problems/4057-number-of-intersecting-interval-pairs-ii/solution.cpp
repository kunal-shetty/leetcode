// 4057. Number of Intersecting Interval Pairs II
// Difficulty: Medium
// https://leetcode.com/problems/number-of-intersecting-interval-pairs-ii/
// Runtime: 202 ms (beats —)
// Memory: 307.3 MB (beats —)
// Submitted: 2026-09-20

class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        vector<int> start, ends;
        for(auto interval : intervals){
            start.push_back(interval[0]);
            ends.push_back(interval[1]);
        }
        sort(start.begin(), start.end());
        sort(ends.begin(), ends.end());
        long long res = 0;
        int i = 0, j = 0;
         for(auto s : start){
             while(ends[j] < s) j++;
             res += i - j;
             i++;
         }
        return res;
    }
};

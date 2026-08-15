// 4020. Elevator Requests I
// Difficulty: Easy
// https://leetcode.com/problems/elevator-requests-i/
// Runtime: 0 ms (beats —)
// Memory: 31.1 MB (beats —)
// Submitted: 2026-08-15

class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int c=0, t=0;
        for(auto r : requests){
            t += abs(c- r);
            c =r;
        }
        return t;
    }
};

// 1653. Minimum Deletions to Make String Balanced
// Difficulty: Medium
// https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/
// Runtime: 12 ms (beats —)
// Memory: 25.5 MB (beats —)
// Submitted: 2026-02-07

class Solution {
public:
    int minimumDeletions(string s) {
        int res = 0, count = 0;
        for (char c : s){
            if (c == 'b')
                count++;
            else if (count){
                res++;
                count--;
            }
        }
        return res;
    }
};

// 1221. Split a String in Balanced Strings
// Difficulty: Easy
// https://leetcode.com/problems/split-a-string-in-balanced-strings/
// Runtime: 0 ms (beats —)
// Memory: 8.3 MB (beats —)
// Submitted: 2026-06-23

class Solution {
public:
    int balancedStringSplit(string s) {
        int count = 0;
        int balance = 0;
        for(auto c : s){
            if(c == 'R') balance++;
            else balance--;
            if(balance == 0) count++;
        }
        return count;
    }
};

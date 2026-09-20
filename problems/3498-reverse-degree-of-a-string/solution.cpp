// 3498. Reverse Degree of a String
// Difficulty: Easy
// https://leetcode.com/problems/reverse-degree-of-a-string/
// Runtime: 3 ms (beats —)
// Memory: 10 MB (beats —)
// Submitted: 2026-09-20

class Solution {
public:
    int reverseDegree(string s) {
        string map = "zyxwvutsrqponmlkjihgfedcba";
        int degree = 0;
        for(int i = 0; i < s.length(); i++){
            degree += (map.find(s[i]) + 1) * (i + 1);
        }
        return degree;
    }
};

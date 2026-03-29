// 3884. First Matching Character From Both Ends
// Difficulty: Easy
// https://leetcode.com/problems/first-matching-character-from-both-ends/
// Runtime: 0 ms (beats —)
// Memory: 8.8 MB (beats —)
// Submitted: 2026-03-29

class Solution {
public:
    int firstMatchingIndex(string s) {
        int n = s.length();
        for(int i = 0; i < n; i++){
            if(s[i] == s[n - i - 1]) return i;
        }
        return -1;
    }
};

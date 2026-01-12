// 58. Length of Last Word
// Difficulty: Easy
// https://leetcode.com/problems/length-of-last-word/
// Runtime: 0 ms (beats —)
// Memory: 8.8 MB (beats —)
// Submitted: 2026-01-12

class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        bool wordFound = false;
        for(int i = s.length() - 1; i >= 0; i--){
            if(s[i] == ' ' && !wordFound) continue;
            count++; wordFound = true; 
            if(s[i] == ' ') {
                count --; 
                return count;
            }
        }
        return count;
    }
};

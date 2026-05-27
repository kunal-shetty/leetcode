// 3121. Count the Number of Special Characters II
// Difficulty: Medium
// https://leetcode.com/problems/count-the-number-of-special-characters-ii/
// Runtime: 92 ms (beats —)
// Memory: 24.1 MB (beats —)
// Submitted: 2026-05-27

class Solution {
public:
    int numberOfSpecialChars(string word) {
        int count = 0;
        for(char c = 'a'; c <= 'z'; c++){
            auto i = word.rfind(c);
            auto j = word.find(toupper(c));
            if(i != string::npos && j != string::npos && i < j) count++;
        }
        return count;
    }
};

// 520. Detect Capital
// Difficulty: Easy
// https://leetcode.com/problems/detect-capital/
// Runtime: 0 ms (beats —)
// Memory: 8.2 MB (beats —)
// Submitted: 2026-08-02

class Solution {
public:
    bool detectCapitalUse(string word) {
        int capitals = 0;
        for(auto c : word){
            if(isupper(c)) capitals++;
        }
        if(word.length() == capitals) return true;
        else if(capitals == 0) return true;
        else if(capitals == 1 && isupper(word[0])) return true;
        return false;
    }
};

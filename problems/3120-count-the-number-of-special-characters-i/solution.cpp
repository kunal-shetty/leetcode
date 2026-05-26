// 3120. Count the Number of Special Characters I
// Difficulty: Easy
// https://leetcode.com/problems/count-the-number-of-special-characters-i/
// Runtime: 4 ms (beats —)
// Memory: 9.6 MB (beats —)
// Submitted: 2026-05-26

class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> set(word.begin(), word.end());
        int count = 0;
        for(char ch : set){
            if(isupper(ch) && set.contains(tolower(ch))) count++;
        }
        return count;
    }
};

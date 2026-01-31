// 744. Find Smallest Letter Greater Than Target
// Difficulty: Easy
// https://leetcode.com/problems/find-smallest-letter-greater-than-target/
// Runtime: 0 ms (beats —)
// Memory: 19.9 MB (beats —)
// Submitted: 2026-01-31

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for(int i = 0;i < letters.size(); i ++){
            if(letters[i] > target)
                return letters[i];
        }
        return letters[0];
    }
};

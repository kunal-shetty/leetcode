// 3541. Find Most Frequent Vowel and Consonant
// Difficulty: Easy
// https://leetcode.com/problems/find-most-frequent-vowel-and-consonant/
// Runtime: 7 ms (beats —)
// Memory: 9.7 MB (beats —)
// Submitted: 2026-07-30

class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int maxFreqSum(string s) {

        unordered_map<char, int> freq;
        for (auto c : s) {
            freq[c]++;
        }
        int consonant = 0, vowel = 0;
        for (auto entry : freq) {
            if (isVowel(entry.first))
                vowel = max(vowel, entry.second);
            else
                consonant = max(consonant, entry.second);
        }
        return consonant + vowel;
    }
};

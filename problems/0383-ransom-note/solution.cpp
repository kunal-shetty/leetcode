// 383. Ransom Note
// Difficulty: Easy
// https://leetcode.com/problems/ransom-note/
// Runtime: 5 ms (beats 31.0%)
// Memory: 12.7 MB (beats 7.3%)
// Submitted: 2026-10-31

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> freq;

        for (auto c : magazine) freq[c]++;

        for (auto c : ransomNote) {
            if (freq[c] <= 0) return false;
            freq[c]--;
        }

        return true;
    }
};

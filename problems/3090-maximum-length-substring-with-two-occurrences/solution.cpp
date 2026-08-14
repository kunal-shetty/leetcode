// 3090. Maximum Length Substring With Two Occurrences
// Difficulty: Easy
// https://leetcode.com/problems/maximum-length-substring-with-two-occurrences/
// Runtime: 0 ms (beats —)
// Memory: 9.6 MB (beats —)
// Submitted: 2026-08-14

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int start = 0;
        int maxLen = 0;
        unordered_map<char, int> freq;

        for (int end = 0; end < s.size(); end++) {
            freq[s[end]]++;

            while (freq[s[end]] > 2) {
                freq[s[start]]--;
                start++;
            }

            maxLen = max(maxLen, end - start + 1);
        }

        return maxLen;
    }
};

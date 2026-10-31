// 1768. Merge Strings Alternately
// Difficulty: Easy
// https://leetcode.com/problems/merge-strings-alternately/
// Runtime: 3 ms (beats 37.2%)
// Memory: 8.4 MB (beats 80.8%)
// Submitted: 2026-10-31

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int l1 = word1.size(), l2 = word2.size(), i = 0;
        string res = "";

        for (i = 0; i < min(l1, l2); i++) {
            res += word1[i];
            res += word2[i];
        }

        while (i < l1) res += word1[i++];
        while (i < l2) res += word2[i++];

        return res;
    }
};

// 28. Find the Index of the First Occurrence in a String
// Difficulty: Easy
// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
// Runtime: 0 ms (beats —)
// Memory: 8.7 MB (beats —)
// Submitted: 2025-05-04

class Solution {
public:					
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        if (m == 0) return 0;

        for (int i = 0; i <= n - m; i++) {
            int j = 0;
            while (j < m && haystack[i + j] == needle[j]) {
                j++;
            }
            if (j == m) return i;
        }

        return -1;
    }
};

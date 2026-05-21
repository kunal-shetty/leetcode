// 3043. Find the Length of the Longest Common Prefix
// Difficulty: Medium
// https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/
// Runtime: 346 ms (beats —)
// Memory: 152.9 MB (beats —)
// Submitted: 2026-05-21

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> prefixes;
        for (int num : arr1) {
            string s = to_string(num);
            string current = "";
            for (char ch : s) {
                current += ch;
                prefixes.insert(current);
            }
        }
        int ans = 0;
        for (int num : arr2) {
            string s = to_string(num);
            string current = "";
            for (int i = 0; i < s.size(); i++) {
                current += s[i];
                if (prefixes.count(current)) {
                    ans = max(ans, i + 1);
                }
            }
        }
        return ans;
    }
};

// 14. Longest Common Prefix
// Difficulty: Easy
// https://leetcode.com/problems/longest-common-prefix/
// Runtime: 0 ms (beats —)
// Memory: 11.6 MB (beats —)
// Submitted: 2025-04-18

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";

    string result = "";
    for (int i = 0; i < strs[0].size(); i++) {
        char c = strs[0][i];
        for (int j = 1; j < strs.size(); j++) {
            if (i >= strs[j].size() || strs[j][i] != c)
                return result;
        }
        result += c;
    }
    return result;
}

};

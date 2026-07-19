// 1081. Smallest Subsequence of Distinct Characters
// Difficulty: Medium
// https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/
// Runtime: 0 ms (beats —)
// Memory: 8.8 MB (beats —)
// Submitted: 2026-07-19

class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last(26);
        vector<bool> visited(26, false);

        for (int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
        }

        string ans;

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];

            if (visited[ch - 'a']) continue;

            while (!ans.empty() &&
                   ans.back() > ch &&
                   last[ans.back() - 'a'] > i) {
                visited[ans.back() - 'a'] = false;
                ans.pop_back();
            }

            ans.push_back(ch);
            visited[ch - 'a'] = true;
        }

        return ans;
    }
};

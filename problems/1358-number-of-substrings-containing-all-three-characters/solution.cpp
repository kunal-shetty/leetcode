// 1358. Number of Substrings Containing All Three Characters
// Difficulty: Medium
// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
// Runtime: 3 ms (beats —)
// Memory: 11 MB (beats —)
// Submitted: 2026-06-30

class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> last(3, -1);
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
            ans += min(last[0], min(last[1], last[2])) + 1;
        }

        return ans;
    }
};

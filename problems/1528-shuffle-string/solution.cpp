// 1528. Shuffle String
// Difficulty: Easy
// https://leetcode.com/problems/shuffle-string/
// Runtime: 0 ms (beats —)
// Memory: 18.7 MB (beats —)
// Submitted: 2026-07-14

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string ans(s.size(), ' ');

        for (int i = 0; i < s.size(); i++)
            ans[indices[i]] = s[i];

        return ans;
    }
};

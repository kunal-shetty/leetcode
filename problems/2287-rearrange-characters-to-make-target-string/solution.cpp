// 2287. Rearrange Characters to Make Target String
// Difficulty: Easy
// https://leetcode.com/problems/rearrange-characters-to-make-target-string/
// Runtime: 0 ms (beats —)
// Memory: 8.4 MB (beats —)
// Submitted: 2026-06-22

class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int> S(26, 0);
        vector<int> T(26, 0);

        for (char c : s)
            S[c - 'a']++;

        for (char c : target)
            T[c - 'a']++;

        int ans = INT_MAX;

        for (int i = 0; i < 26; i++) {
            if (T[i] > 0) ans = min(ans, S[i] / T[i]); 
        }

        return ans;
    }
};

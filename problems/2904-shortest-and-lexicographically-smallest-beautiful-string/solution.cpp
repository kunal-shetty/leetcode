// 2904. Shortest and Lexicographically Smallest Beautiful String
// Difficulty: Medium
// https://leetcode.com/problems/shortest-and-lexicographically-smallest-beautiful-string/
// Runtime: 1 ms (beats —)
// Memory: 9 MB (beats —)
// Submitted: 2026-08-26

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {

        vector<int> ones;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                ones.push_back(i);
            }
        }
        if (ones.size() < k) return "";

        string ans = "";
        for (int i = 0; i + k - 1 < ones.size(); i++) {

            int start = ones[i];
            int end = ones[i + k - 1];

            string cur = s.substr(start, end - start + 1);

            if (ans == "" ||
                cur.size() < ans.size() ||
                (cur.size() == ans.size() && cur < ans)) {

                ans = cur;
            }
        }

        return ans;
    }
};

// 205. Isomorphic Strings
// Difficulty: Easy
// https://leetcode.com/problems/isomorphic-strings/
// Runtime: 0 ms (beats —)
// Memory: 9.3 MB (beats —)
// Submitted: 2026-08-08

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> st, ts;

        for (int i = 0; i < s.size(); i++) {
            char a = s[i], b = t[i];

            if (st.count(a) && st[a] != b) return false;
            if (ts.count(b) && ts[b] != a) return false;

            st[a] = b;
            ts[b] = a;
        }

        return true;
    }
};
